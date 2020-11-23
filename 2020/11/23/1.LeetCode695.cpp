/*************************************************************************
	> File Name: 1.LeetCode695.cpp
	> Author:赵睿 
	> Mail: 1767153298@qq.com
	> Created Time: 2020年11月23日 星期一 14时17分42秒
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

int dir[4][2] = {0, 1, 0, -1, 1, 0, -1, 0};

int dfs(vector<vector<int>> &grid, vector<vector<int>> &check, int x, int y, int &len, int &width) {
    if (x < 0 || x >= len || y < 0 || y >= width) return 0;
    if (check[x][y]) return 0;
    check[x][y] = 1;
    if (grid[x][y] == 0)  return 0;
    int ret = 1;
    for (int i = 0; i < 4; i++) ret += dfs(grid, check, x + dir[i][0], y + dir[i][1], len, width);
    return ret;
}

int maxAreaOfIsland(vector<vector<int>>& grid) {
    if (!grid.size() || !grid[0].size()) return 0;
    int len = grid.size(), width = grid[0].size(), ans = 0;
    vector<vector<int>> check(len, vector<int>(width, 0));
    for (int i = 0; i < len; i++) {
        for (int j = 0; j < width; j++) {
            int temp = dfs(grid, check, i, j, len, width);
            ans = max(ans, temp);
        }
    }
    return ans;
}

int main() {
    return 0;
}
