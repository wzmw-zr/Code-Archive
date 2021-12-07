/*************************************************************************
	> File Name: 2.LeetCode1034.cpp
	> Author: 
	> Mail: 
	> Created Time: 2021年12月07日 星期二 09时41分05秒
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

vector<vector<int>> colorBorder(vector<vector<int>>& grid, int row, int col, int color) {
    int m = grid.size(), n = grid[0].size();
    vector<vector<int>> check(m, vector<int>(n, 0));
    vector<PII> pos;
    queue<PII> que;
    que.push(PII(row, col));
    while (!que.empty()) {
        auto temp = que.front();
        que.pop();
        check[temp.first][temp.second] = 1;
        int flag = 0;
        for (int i = 0; i < 4; i++)  {
            int x = temp.first + dir[i][0];
            int y = temp.second + dir[i][1];
            if (x < 0 || x >= m || y < 0 || y >= n || grid[x][y] != grid[row][col]) {
                flag = 1;
                continue;
            }
            if (check[x][y]) continue;
            que.push(PII(x, y));
        }
        if (flag) pos.push_back(temp);
    }
    for (auto &&[x, y] : pos) grid[x][y] = color;
    return grid;
}

int main() {
    return 0;
}
