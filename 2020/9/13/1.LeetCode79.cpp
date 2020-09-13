/*************************************************************************
	> File Name: 1.LeetCode79.cpp
	> Author:赵睿 
	> Mail: 1767153298@qq.com
	> Created Time: 2020年09月13日 星期日 07时41分26秒
 ************************************************************************/

#include<iostream>
#include<string>
#include<vector>
#include<queue>
#include<stack>
#include<map>
#include<algorithm>
using namespace std;

int dir[4][2] = {1, 0, -1, 0, 0, 1, 0, -1}; 

bool dfs(vector<vector<char>> &board, vector<vector<bool>> &check, int x, int y, string &word, int ind) {
    if (ind == word.size()) return true;
    if (x < 0 || x >= board.size() || y < 0 || y >= board[0].size()) return false;
    if (board[x][y] != word[ind]) return false;
    check[x][y] = 1;
    bool ret = false;
    for (int i = 0; i < 4; i++) {
        int x_t = x + dir[i][0];
        int y_t = y + dir[i][1];
        if (x_t < 0 || x_t >= board.size() || y_t < 0 || y_t >= board[0].size()) continue;
        if (check[x_t][y_t]) continue;
        ret |= dfs(board, check, x_t, y_t, word, ind + 1);
    }
    check[x][y] = 0;
    return ret;
}

bool exist(vector<vector<char>>& board, string word) {
    int h = board.size(), w = board[0].size();
    vector<vector<bool>> check(h + 5, vector<bool>(w + 5, 0));
    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
            if (dfs(board, check, i, j, word, 0)) return true;
        }
    }
    return false;
}

int main() {
    int n, m;
    cin >> n >> m;
    vector<vector<char>> board(n, vector<char>(m, '0'));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> board[i][j];
        }
    }
    string word;
    while (cin >> word) { 
        cout << word << endl;
        cout << (exist(board, word) ? "Yes" : "No") << endl;
    }
    return 0;
}
