/*************************************************************************
	> File Name: 1.LeetCode1020.cpp
	> Author: 
	> Mail: 
	> Created Time: 2022年02月12日 星期六 00时07分41秒
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

void dfs(vector<vector<int>> &grid, vector<vector<int>> &check, int x, int y, int &cnt, int &flag) {
    int m = grid.size(), n = grid[0].size();
    if (x < 0 || x >= m || y < 0 || y >= n || check[x][y] || grid[x][y] == 0) {
        return ;
    }
    check[x][y] = 1;
    cnt++;
    for (int i = 0; i < 4; i++) {
        int x_t = x + dir[i][0];
        int y_t = y + dir[i][1];
        dfs(grid, check, x_t, y_t, cnt, flag);
        if (x_t < 0 || x_t >= m || y_t < 0 || y_t >= n) {
            flag = 0;
        }
    }
}

int numEnclaves(vector<vector<int>>& grid) {
    int m = grid.size(), n = grid[0].size();
    vector<vector<int>> check(m, vector<int>(n, 0));
    int ans = 0;
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (grid[i][j] == 0 || check[i][j]) {
                continue;
            }
            int cnt = 0;
            int flag = 1;
            dfs(grid, check, i, j, cnt, flag);
            ans += cnt * flag;
        }
    }
    return ans;
}

int main() {
    return 0;
}
