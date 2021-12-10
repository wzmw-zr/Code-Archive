/*************************************************************************
	> File Name: 2.LeetCode694.cpp
	> Author: 
	> Mail: 
	> Created Time: 2021年12月10日 星期五 09时18分35秒
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

void dfs(vector<vector<int>> &grid, vector<vector<int>> &check, int x, int y, int &top, int &down, int &left, int &right, int &ind) {
    if (x < 0 || x >= grid.size() || y < 0 || y >= grid[0].size() || check[x][y] || grid[x][y] == 0) return ;
    top = min(top, x);
    down = max(down, x);
    left = min(left, y);
    right = max(right, y);
    check[x][y] = ind;
    for (int i = 0; i < 4; i++) {
        int x_t = x + dir[i][0];
        int y_t = y + dir[i][1];
        if (x_t < 0 || x_t >= grid.size() || y_t < 0 || y_t >= grid[0].size() || check[x_t][y_t] || grid[x_t][y_t] == 0) continue;
        dfs(grid, check, x_t, y_t, top, down, left, right, ind);
    }
}

vector<vector<int>> clip(vector<vector<int>> &grid, vector<vector<int>> &check, int top, int down, int left, int right, int ind) {
    vector<vector<int>> patch;
    for (int i = top; i <= down; i++) {
        vector<int> temp;
        for (int j = left; j <= right; j++) {
            if (check[i][j] == ind) temp.push_back(grid[i][j]);
            else temp.push_back(0);
        }
        patch.push_back(temp);
    }
    return patch;
}

int numDistinctIslands(vector<vector<int>>& grid) {
    int m = grid.size(), n = grid[0].size();
    vector<vector<int>> check(m, vector<int>(n, 0));
    set<vector<vector<int>>> st;
    int ind = 1;
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (check[i][j] || grid[i][j] == 0) continue;
            int top = i, down = i, left = j, right = j;
            dfs(grid, check, i, j, top, down, left, right, ind);
            auto patch = clip(grid, check, top, down, left, right, ind);
            st.insert(patch);
            ind++;
        }
    }
    return st.size();
}

int main() {
    return 0;
}
