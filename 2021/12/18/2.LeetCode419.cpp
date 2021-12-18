/*************************************************************************
	> File Name: 2.LeetCode419.cpp
	> Author: 
	> Mail: 
	> Created Time: 2021年12月18日 星期六 09时49分39秒
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

int dir[2][2] = {-1, 0, 0, -1};

int countBattleships(vector<vector<char>>& board) {
    int m = board.size(), n = board[0].size();
    int ans = 0;
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (board[i][j] == '.') continue;
            int flag = 1;
            for (int k = 0; k < 2; k++) {
                int x = i + dir[k][0];
                int y = j + dir[k][1];
                if (x < 0 || x >= m || y < 0 || y >= n || board[x][y] == '.')  continue;
                flag = 0;
                break;
            }
            ans += flag;
        }
    }
    return ans;
}

int main() {
    return 0;
}
