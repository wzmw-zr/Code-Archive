/*************************************************************************
	> File Name: 1.LeetCode794.cpp
	> Author: 
	> Mail: 
	> Created Time: 2021年12月09日 星期四 09时15分14秒
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

bool validTicTacToe(vector<string>& board) {
    unordered_map<char, int> mp;
    for (auto x : board) {
        for (auto y : x) mp[y]++;
    }
    if (mp['O'] > mp['X']) return false;
    if (mp['X'] - 1 > mp['O']) return false;
    vector<int> cnt(2, 0);
    for (int i = 0; i < 3; i++) {
        if (board[i][0] == board[i][1] && board[i][0] == board[i][2]) {
            if (board[i][0] == 'X') cnt[0]++;
            if (board[i][0] == 'O') cnt[1]++;
        }
        if (board[0][i] == board[1][i] && board[0][i] == board[2][i]) {
            if (board[0][i] == 'X') cnt[0]++;
            if (board[0][i] == 'O') cnt[1]++;
        }
    }
    if (board[0][0] == board[1][1] && board[0][0] == board[2][2]) {
        if (board[0][0] == 'X') cnt[0]++;
        if (board[0][0] == 'O') cnt[1]++;
    }
    if (board[0][2] == board[1][1] && board[0][2] == board[2][0]) {
        if (board[0][2] == 'X') cnt[0]++;
        if (board[0][2] == 'O') cnt[1]++;
    }
    if (cnt[0] && cnt[1]) return false;
    if (cnt[0] && mp['O'] == mp['X']) return false;
    if (cnt[1] && mp['O'] != mp['X']) return false;
    return true;
}

int main() {
    return 0;
}
