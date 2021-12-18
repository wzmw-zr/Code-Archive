/*************************************************************************
	> File Name: 1.LeetCode419.cpp
	> Author: 
	> Mail: 
	> Created Time: 2021年12月18日 星期六 09时29分10秒
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

int dir[2][2] = {1, 0, 0, 1};

void dfs(vector<vector<char>> &board, vector<vector<int>> &check, int x, int y) {
    int m = board.size(), n = board[0].size();
    if (x < 0 || x >= m || y < 0 || y >= n || board[x][y] == '.' || check[x][y]) return ;
    check[x][y] = 1;
    for (int i = 0; i < 2; i++) {
        int x_t = x + dir[i][0];
        int y_t = y + dir[i][1];
        dfs(board, check, x_t, y_t);
    }
}

int countBattleships(vector<vector<char>>& board) {
    int m = board.size(), n = board[0].size();
    vector<vector<int>> check(m, vector<int>(n, 0));
    int ans = 0;
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (board[i][j] == '.' || check[i][j]) continue;
            dfs(board, check, i, j);
            ans++;
        }
    }
    return ans;
}

int main() {
    return 0;
}
