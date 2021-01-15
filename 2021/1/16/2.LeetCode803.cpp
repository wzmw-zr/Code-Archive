/*************************************************************************
	> File Name: 2.LeetCode803.cpp
	> Author: 
	> Mail: 
	> Created Time: 2021年01月16日 星期六 00时11分30秒
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

bool link_to_top(vector<vector<int>> &grid, int x, int y, int &h, int &w, vector<vector<bool>> &check) {
    if (x < 0 || x >= h || y < 0 || y >= w || !grid[x][y] || check[x][y]) return false;
    if (x == 0) return true;
    check[x][y] = true;
    bool ans = false;
    for (int i = 0; i < 4 && !ans; i++) {
        int x_t = x + dir[i][0];
        int y_t = y + dir[i][1];
        ans |= link_to_top(grid, x_t, y_t, h, w, check);
    }
    return ans;
}

int erase_unstable_blocks(vector<vector<int>> &grid, int x, int y, int &h, int &w) {
    if (x < 0 || x >= h || y < 0 || y >= w || !grid[x][y]) return 0;
    int cnt = 1;
    grid[x][y] = 0;
    for (int i = 0; i < 4; i++) {
        int x_t = x + dir[i][0];
        int y_t = y + dir[i][1];
        cnt += erase_unstable_blocks(grid, x_t, y_t, h, w);
    }
    return cnt;
}

vector<int> hitBricks(vector<vector<int>>& grid, vector<vector<int>>& hits) {
    vector<int> ans;
    int h = grid.size(), w = grid[0].size();
    for (auto &x : hits) {
        vector<vector<bool>> check(h, vector<bool>(w, false));
        int cnt = 0;
        grid[x[0]][x[1]] = 0;
        for (int i = 0; i < 4; i++) {
            int x_t = x[0] + dir[i][0];
            int y_t = x[1] + dir[i][1];
            if (x_t < 0 || x_t >= h || y_t < 0 || y_t >= w || !grid[x_t][y_t] || check[x_t][y_t]) continue;
            if (link_to_top(grid, x_t, y_t, h, w, check)) continue;
            cnt += erase_unstable_blocks(grid, x_t, y_t, h, w);
        }
        ans.push_back(cnt);
    }
    return ans;
}

int main() {
    return 0;
}
