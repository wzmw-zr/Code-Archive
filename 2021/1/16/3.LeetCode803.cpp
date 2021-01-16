/*************************************************************************
	> File Name: 3.LeetCode803.cpp
	> Author: 
	> Mail: 
	> Created Time: 2021年01月16日 星期六 08时59分13秒
 ************************************************************************/

#include<iostream>
#include<string>
#include<vector>
#include<queue>
#include<stack>
#include<map>
#include<set>
#include<unordered_map>
#include<unordered_set>
#include<algorithm>
using namespace std;

int dir[4][2] = {1, 0, -1, 0, 0, 1, 0, -1};

struct UnionSet {
    int n;
    vector<int> fa;
    vector<int> sz;
    UnionSet() = default;
    UnionSet(int n) : n(n), fa(n), sz(n) {
        for (int i = 0; i < n; i++) {
            fa[i] = i;
            sz[i] = 1;
        }
    }
    int get(int x) {
        return fa[x] = (x == fa[x] ? x : get(fa[x]));
    }
    void merge(int x, int y) {
        int a = get(x);
        int b = get(y);
        if (a == b) return ;
        if (a < b) {
            fa[b] = a;
            sz[a] += sz[b];
        } else {
            fa[a] = b;
            sz[b] += sz[a];
        }
    }
    int size(int x) {
        return sz[get(x)];
    }
};

vector<int> hitBricks(vector<vector<int>>& grid, vector<vector<int>>& hits) {
    int h = grid.size(), w = grid[0].size();
    auto status = grid;
    for (auto &x : hits) status[x[0]][x[1]] = 0;
    UnionSet u(h * w + 1);
    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
            if (status[i][j] == 0) continue;
            if (i == 0) u.merge(0, i * w + j + 1);
            if (i > 0 && status[i - 1][j]) u.merge((i - 1) * w + j + 1, i * w + j + 1);
            if (j > 0 && status[i][j - 1]) u.merge(i * w + j, i * w + j + 1);
        }
    }
    vector<int> ans(hits.size(), 0);
    for (int i = hits.size() - 1; i >= 0; i--) {
        int x = hits[i][0], y = hits[i][1];
        if (!grid[x][y]) {
            ans.push_back(0);
            continue;
        }
        int pre = u.size(0);
        if (x == 0) u.merge(0, y + 1);
        for (int i = 0; i < 4; i++) {
            int x_t = x + dir[i][0]; 
            int y_t = y + dir[i][1];
            if (x_t < 0 || x_t >= h || y_t < 0 || y_t >= w || !status[x_t][y_t]) continue;
            u.merge(x * w + y + 1, x_t * w + y_t + 1);
        }
        ans[i] = max(0, u.size(0) - pre - 1);
        status[x][y] = 1;
    }
    return ans;
}

int main() {
    return 0;
}
