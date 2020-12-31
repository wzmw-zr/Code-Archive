/*************************************************************************
	> File Name: 2.LeetCode1034.cpp
	> Author: 
	> Mail: 
	> Created Time: 2021年01月01日 星期五 00时18分30秒
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

typedef pair<int, int> PII;

int dir[4][2] = {1, 0, -1, 0, 0, 1, 0, -1};

bool dfs(vector<vector<int>> &grid, int x, int y, int &h, int &w, vector<PII> &bounder, int color, vector<vector<bool>> &check) {
    if (x < 0 || x >= h || y < 0 || y >= w) return true;
    if (grid[x][y] - color) return true;
    if (check[x][y]) return false;
    check[x][y] = true;
    bool ans = false;
    for (int i = 0; i < 4; i++) ans |= dfs(grid, x + dir[i][0], y + dir[i][1], h, w, bounder, color, check);
    if (ans) bounder.push_back(PII(x, y));
    return false;
}

vector<vector<int>> colorBorder(vector<vector<int>>& grid, int r0, int c0, int color) {
    int h = grid.size(), w = grid[0].size();
    vector<PII> bounder;
    vector<vector<bool>> check(h, vector<bool>(w, false));
    dfs(grid, r0, c0, h, w, bounder, grid[r0][c0], check);
    for (auto &&[x, y] : bounder) grid[x][y] = color;
    return grid;
}

int main() {
    return 0;
}
