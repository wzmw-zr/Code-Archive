/*************************************************************************
	> File Name: 2.LeetCode827.cpp
	> Author: 
	> Mail: 
	> Created Time: 2021年12月11日 星期六 09时32分00秒
 ************************************************************************/

#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <stack>
#include <map>
#include <set>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>
using namespace std;

int wzmw_zr = 0;
bool fuck_plagiarism_system_of_leetcode = true;

struct UnionSet {
    vector<int> fa;
    vector<int> cnt;

    UnionSet(int n) : fa(vector<int>(n, 0)), cnt(vector<int>(n, 1)) {
        for (int i = 0; i < n; i++) fa[i] = i;
    }

    int find(int x) {
        return fa[x] = x == fa[x] ? x : find(fa[x]);
    }

    void merge(int x, int y) {
        int a = find(x);
        int b = find(y);
        if (a == b) return ;
        fa[a] = b;
        cnt[b] += cnt[a];
    }

    int query(int x) {
        int a = find(x);
        return cnt[a];
    }
};

int dir[4][2] = {1, 0, -1, 0, 0, 1, 0, -1};

int largestIsland(vector<vector<int>>& grid) {
    int m = grid.size(), n = grid[0].size();
    UnionSet u(m * n);
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (!grid[i][j]) continue;
            for (int k = 0; k < 4; k++) {
                int x = i + dir[k][0];
                int y = j + dir[k][1];
                if (x < 0 || x >= m || y < 0 || y >= n || !grid[x][y]) continue;
                u.merge(i * m + j, x * m + y);
            }
        }
    }
    int ans = 0;
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (grid[i][j]) {
                ans = max(ans, u.query(i * m + j));
                continue;
            }
            int cnt = 0;
            unordered_set<int> st;
            for (int k = 0; k < 4; k++) {
                int x = i + dir[k][0];
                int y = j + dir[k][1];
                if (x < 0 || x >= m || y < 0 || y >= n || !grid[x][y]) continue;
                int id = u.find(x * m + y);
                if (st.count(id)) continue;
                cnt += u.query(x * m + y);
                st.insert(id);
            }
            ans = max(ans, cnt + 1);
        }
    }
    return ans;
}

int main() {
    return 0;
}
