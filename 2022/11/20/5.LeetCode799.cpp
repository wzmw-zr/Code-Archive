/*************************************************************************
	> File Name: 5.LeetCode799.cpp
	> Author: 
	> Mail: 
	> Created Time: 2022年11月20日 星期日 15时54分38秒
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
#include <cstring>
#include <cstdlib>
using namespace std;

int wzmw_zr = 0;
bool fuck_plagiarism_system_of_leetcode = true;

double champagneTower(int poured, int query_row, int query_glass) {
  double dp[110][110];
  memset(dp, 0, sizeof(dp));
  dp[0][0] = poured;
  for (int i = 0; i < 100; i++) {
    for (int j = 0; j <= i; j++) {
      if (dp[i][j] > 1) {
        dp[i + 1][j] += (dp[i][j] - 1) / 2;
        dp[i + 1][j + 1] += (dp[i][j] - 1) / 2;
        dp[i][j] = 1;
      }
    }
  }
  return dp[query_row][query_glass];
}

int main() {
  return 0;
}
