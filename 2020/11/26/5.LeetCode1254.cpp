/*************************************************************************
	> File Name: 5.LeetCode1254.cpp
	> Author:赵睿 
	> Mail: 1767153298@qq.com
	> Created Time: 2020年11月26日 星期四 20时39分07秒
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

int dfs(vector<vector<int>> &grid, vector<vector<int>> &check, int x, int y, int &l, int &w) {
    if (x < 0 || x >= l || y < 0 || y >= w) return 0;
    if (check[x][y]) return 1;
    check[x][y] = 1;
    if (grid[x][y]) return 1;
    int ans = 1;
    for (int i = 0; i < 4; i++) {
        int x_t = x + dir[i][0], y_t = y + dir[i][1];
        ans &= dfs(grid, check, x_t, y_t, l, w);
    }
    return ans;
}

int closedIsland(vector<vector<int>>& grid) {
    int l = grid.size(), w = grid[0].size(), ans = 0;
    vector<vector<int>> check(l, vector<int>(w, 0));
    for (int i = 0; i < l; i++) {
        for (int j = 0; j < w; j++) {
            if (check[i][j]) continue;
            if (grid[i][j]) continue;
            if (dfs(grid, check, i, j, l, w)) ans++;
        }
    }
    return ans;
}

int main() {
    return 0;
}
