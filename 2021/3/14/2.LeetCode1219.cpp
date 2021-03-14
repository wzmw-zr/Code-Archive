/*************************************************************************
	> File Name: 2.LeetCode1219.cpp
	> Author: 
	> Mail: 
	> Created Time: 2021年03月14日 星期日 08时26分18秒
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

int dir[4][2] = {0, 1, 0, -1, 1, 0, -1, 0};

void dfs(vector<vector<int>> &grid, vector<vector<int>> &check, int x, int y, int &n, int &m, int path, int &ans) {
    if (x < 0 || x >= n || y < 0 || y >= m || check[x][y]) return ;
    check[x][y] = 1;
    path += grid[x][y];
    int flag = 0;
    for (int i = 0; i < 4; i++) {
        int x_t = x + dir[i][0];
        int y_t = y + dir[i][1];
        if (x_t < 0 || x_t >= n || y_t < 0 || y_t >= m || check[x_t][y_t]) 
            continue;
        flag = 1;
        dfs(grid, check, x_t, y_t, n, m, path, ans);
    }
    check[x][y] = 0;
    if (!flag) ans = max(ans, path);
}

int getMaximumGold(vector<vector<int>>& grid) {
    int n = grid.size(), m = grid[0].size();
    vector<vector<int>> check(n, vector<int>(m, 0));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) check[i][j] = grid[i][j] ? 0 : 1;
    }
    int ans = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) dfs(grid, check, i, j, n, m, 0, ans);
    }
    return ans;
}

int main() {
    return 0;
}
