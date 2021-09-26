/*************************************************************************
	> File Name: 1.LeetCode5883.cpp
	> Author: 
	> Mail: 
	> Created Time: 2021年09月26日 星期日 11时30分30秒
 ************************************************************************/

#include <iostream>
#include <string>
#include <vector>
using namespace std;

// WA
bool check(vector<vector<char>> &board, int x, int y, string &word) {
    int l = word.size();
    int m = board.size(), n = board[0].size();
    if (board[x][y] == word[0]) cout << x << " " << y << " " << word[0] << endl;
    if (x >= l - 1) {
        int flag = 0;
        for (int i = x - l + 1, j = 0; i <= x; i++, j++) {
            if (board[i][y] == ' ' || board[i][y] == word[j]) continue;
            flag = 1;
            break;
        }
        if (!flag && ((x - l + 1 == 0) || board[x - l][y] == '#') && ((x == m - 1) || board[x + 1][y] == '#')) return true;
    }
    if (x + l - 1 < m) {
        int flag = 0;
        for (int i = x, j = 0; i <= x + l - 1; i++, j++) {
            if (board[i][y] == ' ' || board[i][y] == word[j]) continue;
            flag = 1;
            break;
        }
        if (!flag && ((x == 0) || board[x - 1][y] == '#') && ((x + l - 1 == m - 1) || board[x + l][y] == '#')) return true;
    }
    if (y >= l - 1) {
        int flag = 0;
        for (int i = y - l + 1, j = 0; i <= y; i++, j++) {
            if (board[x][i] == ' ' || board[x][i] == word[j]) continue;
            flag = 1;
            break;
        }
        if (!flag && ((y - l + 1 == 0) || board[x][y - l] == '#') && ((y == n - 1) || board[x][y + 1] == '#')) return true;
    }
    if (y + l - 1 < n) {
        int flag = 0; 
        for (int i = y, j = 0; i <= y + l - 1; i++, j++) {
            if (board[x][i] == ' ' || board[x][i] == word[j]) continue;
            flag = 1;
            break;
        }
        if (!flag && ((y == 0) || board[x][y - 1] == '#') && ((y + l - 1 == n - 1) || board[x][y + l] == '#')) return true;
    }
    return false;
}
    
bool placeWordInCrossword(vector<vector<char>>& board, string word) {
    int m = board.size(), n = board[0].size();
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (check(board, i, j, word)) return true;
        }
    }
    return false;
}
