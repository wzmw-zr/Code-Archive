/*************************************************************************
	> File Name: 3.LeetCode5791.cpp
	> Author: 
	> Mail: 
	> Created Time: 2021年06月20日 星期日 11时04分14秒
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

typedef pair<int, int> PII;

int dir[4][2] = {-1, 0, 1, 0, 0, 1, 0, -1};

void dfs(vector<vector<int>> &grid, vector<vector<int>> &check, set<PII> &st, int x, int y, int &m, int &n) {
    if ((x < 0) || (x >= m) || (y < 0) || (y >= n) || check[x][y] || !grid[x][y]) return ;
    check[x][y] = 1;
    st.insert(PII(x, y));
    for (int i = 0; i < 4; i++) 
        dfs(grid, check, st, x + dir[i][0], y + dir[i][1], m, n);
}

void get_island(vector<vector<int>> &grid, vector<set<PII>> &island) {
    int m = grid.size(), n = grid[0].size();
    vector<vector<int>> check(m, vector<int>(n, 0));
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (check[i][j] || !grid[i][j]) continue;
            set<PII> st;
            dfs(grid, check, st, i, j, m, n);
            island.push_back(st);
        }
    }
}

int countSubIslands(vector<vector<int>>& grid1, vector<vector<int>>& grid2) {
    vector<set<PII>> island1, island2;
    int cnt = 0;
    get_island(grid1, island1);
    get_island(grid2, island2);
    for (auto x : island2) {
        int check = 0;
        for (auto y : x) {
            if (grid1[y.first][y.second]) continue;
            check = 1;
            break;
        }
        if (check) continue;
        for (auto y : island1) {
            int flag = 0;
            for (auto z : x) {
                if (y.count(z)) continue;
                flag = 1;
                break;
            }
            if (flag) continue;
            check = 1;
            break;
        }
        if (check) cnt++;
    }
    return cnt;
}

int main() {
    return 0;
}
