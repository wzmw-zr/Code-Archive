/*************************************************************************
	> File Name: 1.LeetCode37.cpp
	> Author:赵睿 
	> Mail: 1767153298@qq.com
	> Created Time: 2020年09月15日 星期二 07时22分51秒
 ************************************************************************/

#include<iostream>
#include<string>
#include<vector>
#include<queue>
#include<stack>
#include<map>
#include<algorithm>
using namespace std;

void solveSudoku(vector<vector<char>>& board) {
    int line[15][15] = {0}, column[15][15] = {0}, block[5][5][15] = {0};
    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            if (board[i][j] == '.') continue;
            line[i][board[i][j]] = 1;
            column[j][board[i][j]] = 1;
            block[i / 3][j / 3][board[i][j]] = 1;
        }
    }
}

int main() {
    return 0;
}
