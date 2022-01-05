/*************************************************************************
	> File Name: 1.LeetCode1020.cpp
	> Author: 
	> Mail: 
	> Created Time: 2022年01月05日 星期三 19时05分37秒
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

int dir[4][2] = {1, 0, -1, 0, 0, 1, 0, -1};

void dfs(vector<vector<int>> &grid, vector<vector<int>> &check, int x, int y, int &flag, int &size) {
    int m = grid.size(), n = grid[0].size();
    if (x < 0 || x >= m || y < 0 || y >= n || !grid[x][y] || check[x][y]) return ;
    check[x][y] = 1;
    size++;
    if (x == 0 || x == m - 1 || y == 0 || y == n - 1) flag = 0;
    for (int i = 0; i < 4; i++) {
        int x_t = x + dir[i][0];
        int y_t = y + dir[i][1];
        if (x_t < 0 || x_t >= m || y_t < 0 || y_t >= n || !grid[x_t][y_t] || check[x_t][y_t]) continue;
        dfs(grid, check, x_t, y_t, flag, size);
    }
}

int numEnclaves(vector<vector<int>>& grid) {
    int m = grid.size(), n = grid[0].size();
    vector<vector<int>> check(m, vector<int>(n, 0));
    int ans = 0;
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (!grid[i][j] || check[i][j]) continue;
            int flag = 1, size = 0;
            dfs(grid, check, i, j, flag, size);
            ans += flag * size;
        }
    }
    return ans;
}

int main() {
    return 0;
}
