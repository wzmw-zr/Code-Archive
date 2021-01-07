/*************************************************************************
	> File Name: 3.LeetCode1391.cpp
	> Author: 
	> Mail: 
	> Created Time: 2021年01月08日 星期五 00时33分31秒
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

int mp[7][2][2] = {{0, 0, 0, 0}, 
                    {1, 3, 3, 1},
                    {2, 4, 4, 2},
                    {1, 4, 4, 1},
                    {3, 4, 4, 3}, 
                    {1, 2, 2, 1},
                    {2, 3, 3, 2}};

int dir[5][2] = {0, 0, 0, -1, -1, 0, 0, 1, 1, 0};

int couple[5] = {0, 3, 4, 1, 2};

bool dfs(int x, int y, int &n, int &m, vector<vector<int>> &grid, vector<vector<bool>> &check, int from) {
    if (x < 0 || x >= n || y < 0 || y >= m) return false;
    if (check[x][y]) return false;
    int id = grid[x][y];
    bool ans = false;
    if (from == -1) {
        if (x == n - 1 && y == m - 1) return true;
        check[x][y] = true;
        for (int i = 0; i < 2; i++) {
            int x_t = x + dir[mp[id][i][1]][0];
            int y_t = y + dir[mp[id][i][1]][1];
            ans |= dfs(x_t, y_t, n, m, grid, check, mp[id][i][1]);
        }
        check[x][y] = false;
        return ans;
    }
    if (from != couple[mp[id][0][0]] && from != couple[mp[id][1][0]]) return false;
    if (x == n - 1 && y == m - 1) return true;
    check[x][y] = true;
    if (from == couple[mp[id][0][0]]) {
        int x_t = x + dir[mp[id][0][1]][0];
        int y_t = y + dir[mp[id][0][1]][1];
        ans |= dfs(x_t, y_t, n, m, grid, check, mp[id][0][1]);
    } else {
        int x_t = x + dir[mp[id][1][1]][0];
        int y_t = y + dir[mp[id][1][1]][1];
        ans |= dfs(x_t, y_t, n, m, grid, check, mp[id][1][1]);
    }
    check[x][y] = false;
    return ans;
}

bool hasValidPath(vector<vector<int>>& grid) {
    int n = grid.size(), m = grid[0].size();
    vector<vector<bool>> check(n, vector<bool>(m, false));
    return dfs(0, 0, n, m, grid, check, -1);
}

int main() {
    return 0;
}
