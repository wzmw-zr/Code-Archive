/*************************************************************************
	> File Name: 2.LeetCode348.cpp
	> Author: 
	> Mail: 
	> Created Time: 2022年02月18日 星期五 19时51分25秒
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

class TicTacToe {
public:
    /** Initialize your data structure here. */
  int n;
  vector<vector<int>> matrix;

  TicTacToe(int n) : n(n), matrix(vector<vector<int>>(n, vector<int>(n, 0))) {}
    
  /** Player {player} makes a move at ({row}, {col}).
      @param row The row of the board.
      @param col The column of the board.
      @param player The player, can be either 1 or 2.
      @return The current winning condition, can be either:
              0: No one wins.
              1: Player 1 wins.
              2: Player 2 wins. */
  int move(int row, int col, int player) {
    matrix[row][col] = player;
    int flag = 1;
    for (int i = 0; i < n; i++) {
      if (matrix[i][col] != player) {
        flag = 0;
        break;
      }
    }
    if (flag) 
      return player;
    
    flag = 1;
    for (int i = 0; i < n; i++) {
      if (matrix[row][i] != player) {
        flag = 0;
        break;
      }
    }
    if (flag)
      return player;

    if (row == col) {
      flag = 1;
      for (int i = 0; i < n; i++) {
        if (matrix[i][i] != player) {
          flag = 0;
          break;
        }
      }
      if (flag) 
        return player;
    }

    if (row + col == n - 1) {
      flag = 1;
      for (int i = 0; i < n; i++) {
        if (matrix[i][n - 1 - i] != player) {
          flag = 0;
          break;
        }
      }
      if (flag)
        return player;
    }

    return 0;
  }
};

int main() {
  return 0;
}
