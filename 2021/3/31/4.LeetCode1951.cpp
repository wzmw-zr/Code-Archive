/*************************************************************************
	> File Name: 4.LeetCode1951.cpp
	> Author: 
	> Mail: 
	> Created Time: 2021年03月31日 星期三 01时08分15秒
 ************************************************************************/

#include<iostream>
#include<vector>
using namespace std;

int dir[2][2] = {0, 1, 1, 0};

bool dfs(vector<vector<int>> &obstacleGrid, vector<vector<int>> &check, int x, int y, int &r, int &c, vector<vector<int>> &path, vector<vector<int>> &ans) {
    if (x < 0 || x >= r || y < 0 || y >= c || obstacleGrid[x][y]) return false;
    check[x][y] = 1;
    if (x == r - 1 && y == c - 1) {
        ans = path;
        return true;
    }
    for (int i = 0; i < 2; i++) {
        int x_t = x + dir[i][0];
        int y_t = y + dir[i][1];
        if (x_t < 0 || x_t >= r || y_t < 0 || y_t >= c || obstacleGrid[x_t][y_t] || check[x_t][y_t])  continue;
        path.push_back({x_t, y_t});
        bool res = dfs(obstacleGrid, check, x_t, y_t, r, c, path, ans);
        path.pop_back();
        if (res) return true;
    }
    return false;
}

vector<vector<int>> pathWithObstacles(vector<vector<int>>& obstacleGrid) {
    int r = obstacleGrid.size(), c = obstacleGrid[0].size();
    vector<vector<int>> check(r, vector<int>(c, 0));
    vector<vector<int>> ans, path;
    path.push_back({0, 0});
    check[0][0] = 1;
    dfs(obstacleGrid, check, 0, 0, r, c, path, ans);
    return ans;
}

int main() {
    return 0;
}
