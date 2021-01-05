/*************************************************************************
	> File Name: 3.LeetCode1750.cpp
	> Author: 
	> Mail: 
	> Created Time: 2021年01月05日 星期二 21时19分46秒
 ************************************************************************/

#include<iostream>
#include<cstring>
#include<cstdlib>
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
bool handled[201][201][201];
bool result[201][201][201];

bool dfs(vector<vector<char>> &board, vector<vector<bool>> &check, int x, int y, string &word, int ind) {
    if (x < 0 || x >= board.size() || y < 0 || y >= board[0].size()) return false;
    if (check[x][y]) return false;
    if (handled[x][y][ind]) return  result[x][y][ind];
    if (board[x][y] != word[ind]) {
        handled[x][y][ind] = true;
        result[x][y][ind] = false;
        return false;
    } 
    if (ind == (int) word.size() - 1) {
        handled[x][y][ind] = true;
        result[x][y][ind] = true;
        return true;
    }
    bool ans = false;
    check[x][y] = true;
    for (int i = 0; i < 4 && !ans; i++) ans |= dfs(board, check, x + dir[i][0], y + dir[i][1], word, ind + 1);
    check[x][y] = false;
    handled[x][y][ind] = true;
    result[x][y][ind] = ans;
    return ans;
}

bool exist(vector<vector<char>>& board, string word) {
    memset(handled, 0, sizeof(handled));
    memset(result, 0, sizeof(result));
    int h = board.size(), w = board[0].size();
    vector<vector<bool>> check(h, vector<bool>(w, false));
    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
            if (dfs(board, check, i, j, word, 0)) return true;
        }
    }
    return false;
}

int main() {
    return 0;
}
