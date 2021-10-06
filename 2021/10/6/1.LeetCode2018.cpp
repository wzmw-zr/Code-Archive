/*************************************************************************
	> File Name: 1.LeetCode2018.cpp
	> Author: 
	> Mail: 
	> Created Time: 2021年10月06日 星期三 22时21分26秒
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

bool check(vector<vector<char>> &board, int x, int y, string &word) {
    if (board[x][y] == '#') return false;
    int m = board.size(), n = board[0].size();
    int l = word.size();
    if (x + l - 1 <= m - 1) {
        if ((x == 0 || board[x - 1][y] == '#') && ((x + l - 1 == m - 1) || board[x + l][y] == '#')) {
            int flag = 0;
            for (int i = x, j = 0; j < l; i++, j++)  {
                if (board[i][y] == ' ' || board[i][y] == word[j]) continue;
                flag = 1;
                break;
            }
            if (!flag) return true;
        }
    }
    if (x - l + 1 >= 0) {
        if (((x - l + 1 == 0) || (board[x - l][y] == '#')) && ((x == m - 1) || (board[x + 1][y] == '#'))) {
            int flag = 0;
            for (int i = x, j = 0; j < l; i--, j++) {
                if (board[i][y] == ' ' || board[i][y] == word[j]) continue;
                flag = 1;
                break;
            }
            if (!flag) return true;
        }
    }
    if (y + l - 1 <= n - 1) {
        if ((y == 0 || board[x][y - 1] == '#') && ((y + l - 1 == n - 1) || (board[x][y + l] == '#'))) {
            int flag = 0;
            for (int i = y, j = 0; j < l; i++, j++) {
                if (board[x][i] == ' ' || board[x][i] == word[j]) continue;
                flag = 1;
                break;
            }
            if (!flag) return true;
        }
    }
    if (y - l + 1 >= 0) {
        if ((y - l + 1 == 0 || board[x][y - l] == '#') && ((y == n - 1) || (board[x][y + 1] == '#'))) {
            int flag = 0;
            for (int i = y, j = 0; j < l; i--, j++) {
                if (board[x][i] == ' ' || board[x][i] == word[j]) continue;
                flag = 1;
                break;
            }
            if (!flag) return true;
        }
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

int main() {
    return 0;
}
