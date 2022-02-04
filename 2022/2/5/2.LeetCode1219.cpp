/*************************************************************************
	> File Name: 2.LeetCode1219.cpp
	> Author: 
	> Mail: 
	> Created Time: 2022年02月05日 星期六 01时40分50秒
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

void dfs(vector<vector<int>> &grid, vector<vector<int>> &check, int x, int y, int path_sum, int &mmax) {
    int m = grid.size(), n = grid[0].size();
    if (x < 0 || x >= m || y < 0 || y >= n || check[x][y] || !grid[x][y]) {
        return ;
    }
    check[x][y] = 1;
    mmax = max(mmax, path_sum);
    for (int i = 0; i < 4; i++) {
        int x_t = x + dir[i][0];
        int y_t = y + dir[i][1];
        if (x_t < 0 || x_t >= m || y_t < 0 || y_t >= n || check[x_t][y_t] || !grid[x_t][y_t]) {
            continue;
        }
        dfs(grid, check, x_t, y_t, path_sum + grid[x_t][y_t], mmax);
    }
    check[x][y] = 0;
}

int getMaximumGold(vector<vector<int>>& grid) {
    int m = grid.size();
    int n = grid[0].size();
    vector<vector<int>> check(m, vector<int>(n, 0));
    int mmax = 0;
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (grid[i][j]) {
                dfs(grid, check, i, j, grid[i][j], mmax);
            }
        }
    }
    return mmax;
}

int main() {
    return 0;
}
