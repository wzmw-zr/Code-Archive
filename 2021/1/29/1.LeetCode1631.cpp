/*************************************************************************
	> File Name: 1.LeetCode1631.cpp
	> Author: 
	> Mail: 
	> Created Time: 2021年01月29日 星期五 00时05分37秒
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

int dir[4][2] = {0, 1, 1, 0, 0, -1, -1, 0};

void dfs(vector<vector<int>> &heights, int x, int y, int &h, int &w, vector<vector<bool>> &check, int &ans, int diff) {
    if (x == h - 1 && y == w - 1) {
        ans = min(ans, diff);
        return ;
    }
    if (x < 0 || x >= h || y < 0 || y >= w) return ;
    if (check[x][y]) return ;
    check[x][y] = true;
    for (int i = 0; i < 4; i++) {
        int x_t = x + dir[i][0];
        int y_t = y + dir[i][1];
        if (x_t < 0 || x_t >= h || y_t < 0 || y_t >= w || check[x_t][y_t]) continue;
        dfs(heights, x_t, y_t, h, w, check, ans, max(diff, abs(heights[x_t][y_t] - heights[x][y])));
    }
    check[x][y] = false;
}

int minimumEffortPath(vector<vector<int>>& heights) {
    int h = heights.size(), w = heights[0].size();
    vector<vector<bool>> check(h, vector<bool>(w, false));
    int ans = INT32_MAX;
    dfs(heights, 0, 0, h, w, check, ans, 0);
    return ans;
}

int main() {
    return 0;
}
