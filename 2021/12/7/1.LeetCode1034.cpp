/*************************************************************************
	> File Name: 1.LeetCode1034.cpp
	> Author: 
	> Mail: 
	> Created Time: 2021年12月07日 星期二 09时25分14秒
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

using PII = pair<int, int>;

int dir[4][2] = {1, 0, -1, 0, 0, 1, 0, -1};

void dfs(vector<vector<int>> &grid, vector<vector<int>> &check, int &m, int &n, vector<PII> &pos, int row, int col, int color) {
    if (row < 0 || row >= m || col < 0 || col >= n || check[row][col] || grid[row][col] != color) return ;
    check[row][col] = 1;
    int flag = 0;
    for (int i = 0; i < 4; i++) {
        int x = row + dir[i][0];
        int y = col + dir[i][1];
        if (x < 0 || x >= m || y < 0 || y >= n || grid[x][y] != color) {
            flag = 1;
            continue;
        }
        if (check[x][y]) continue;
        dfs(grid, check, m, n, pos, x, y, color);
    }
    if (flag) pos.push_back(PII(row, col));
}

vector<vector<int>> colorBorder(vector<vector<int>>& grid, int row, int col, int color) {
    int m = grid.size(), n = grid[0].size();
    vector<vector<int>> check(m, vector<int>(n, 0));
    vector<PII> pos;
    dfs(grid, check, m, n, pos, row, col, grid[row][col]);
    for (auto &&[x, y] : pos) grid[x][y] = color;
    return grid;
}

int main() {
    return 0;
}
