/*************************************************************************
	> File Name: 3.LeetCode711.cpp
	> Author: 
	> Mail: 
	> Created Time: 2021年12月10日 星期五 09时40分27秒
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
    check[x][y] = ind;
    top = min(top, x);
    down = max(down, x);
    left = min(left, y);
    right = max(right, y);
    for (int i = 0; i < 4; i++) {
        int x_t = x + dir[i][0];
        int y_t = y + dir[i][1];
        if (x_t < 0 || x_t >= grid.size() || y_t < 0 || y_t >= grid[0].size() || check[x_t][y_t] || grid[x_t][y_t] == 0) continue;
        dfs(grid, check, x_t, y_t, top, down, left, right, ind);
    }
}

vector<vector<int>> clip(vector<vector<int>> &grid, vector<vector<int>> &check, int top, int down, int left, int right, int ind) {
    vector<vector<int>> patch(down - top + 1, vector<int>(right - left + 1, 0));
    for (int i = top; i <= down; i++) {
        for (int j = left; j <= right; j++) {
            if (check[i][j] == ind) patch[i - top][j - left] = 1;
        }
    }
    return patch;
}

vector<vector<int>> rotate(vector<vector<int>> &patch) {
    int m = patch.size(), n = patch[0].size();
    vector<vector<int>> ans(n, vector<int>(m, 0));
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            ans[j][m - 1 - i] = patch[i][j];
        }
    }
    return ans;
}

vector<vector<int>> h_flip(vector<vector<int>> &patch) {
    int m = patch.size(), n = patch[0].size();
    vector<vector<int>> ans(m, vector<int>(n, 0));
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) ans[i][n - 1 - j] = patch[i][j];
    }
    return ans;
}

vector<vector<int>> v_flip(vector<vector<int>> &patch) {
    int m = patch.size(), n = patch[0].size();
    vector<vector<int>> ans(m, vector<int>(n, 0));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) ans[m - 1 - j][i] = patch[j][i];
    }
    return ans;
}

int numDistinctIslands2(vector<vector<int>>& grid) {
    int m = grid.size(), n = grid[0].size();
    vector<vector<int>> check(m, vector<int>(n, 0));
    int ind = 1;
    int cnt = 0;
    set<vector<vector<int>>> st;
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (grid[i][j] == 0 || check[i][j]) continue;
            int top = i, down = i, left = j, right = j;
            dfs(grid, check, i, j, top, down, left, right, ind);
            auto patch = clip(grid, check, top, down, left, right, ind);
            ind++;
            if (st.count(patch)) continue;
            cnt++;
            for (int k = 0; k < 4; k++) {
                st.insert(patch);
                patch = rotate(patch);
            }
            auto temp = h_flip(patch);
            st.insert(temp);
            temp = rotate(temp);
            st.insert(temp);
            temp = rotate(temp);
            temp = rotate(temp);
            st.insert(temp);
            st.insert(v_flip(patch));
        }
    }
    return cnt;
}

int main() {
    return 0;
}
