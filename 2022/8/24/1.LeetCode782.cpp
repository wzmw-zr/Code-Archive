/*************************************************************************
	> File Name: 1.LeetCode782.cpp
	> Author: 
	> Mail: 
	> Created Time: 2022年08月24日 星期三 16时18分44秒
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

int calculate(int n, int mask) {
  if (n & 1) {
    int ones = __builtin_popcount(mask);
    if (ones * 2 > n) 
      return __builtin_popcount(mask & 0xAAAAAAAA);
    else
      return __builtin_popcount(mask & 0x55555555);
  } 
  return min(__builtin_popcount(mask & 0xAAAAAAAA), __builtin_popcount(mask & 0x55555555));
}

int movesToChessboard(vector<vector<int>>& board) {
  int n = board.size();
  int row_mask = 0, row_reverse_mask = 0;
  int col_mask = 0, col_reverse_mask = 0;
  for (int i = 0; i < n; i++) {
    row_mask |= board[0][i] << i;
    col_mask |= board[i][0] << i;
  }
  row_reverse_mask = ((1 << n) - 1) ^ row_mask;
  col_reverse_mask = ((1 << n) - 1) ^ col_mask;
  
  unordered_map<int, int> mp_1, mp_2;

  for (int i = 0; i < n; i++) {
    int r_mask = 0, c_mask = 0;
    for (int j = 0; j < n; j++) {
      r_mask |= board[i][j] << j;
      c_mask |= board[j][i] << j;
    }
    if (r_mask != row_mask && r_mask != row_reverse_mask)
      return -1;
    if (c_mask != col_mask && c_mask != col_reverse_mask)
      return -1;
    int r_ones = __builtin_popcount(r_mask);
    int c_ones = __builtin_popcount(c_mask);
    if (n & 1) {
      if (abs(n - r_ones * 2) != 1)
        return -1;
      if (abs(n - c_ones * 2) != 1)
        return -1;
    } else {
      if (n != r_ones * 2)
        return -1;
      if (n != c_ones * 2)
        return -1;
    }
    mp_1[r_mask]++;
    mp_2[c_mask]++;
  }

  if (n & 1) {
    if (abs(mp_1[row_mask] * 2 - n) != 1)
      return -1;
    if (abs(mp_2[col_mask] * 2 - n) != 1)
      return -1;
  } else {
    if (mp_1[row_mask] != mp_1[row_reverse_mask])
      return -1;
    if (mp_2[col_mask] != mp_2[col_reverse_mask])
      return -1;
  }

  int ans = 0;
  ans += calculate(n, row_mask) + calculate(n, col_mask);

  return ans;
}

int main() {
  return 0;
}
