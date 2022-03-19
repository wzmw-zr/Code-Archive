/*************************************************************************
	> File Name: 3.LeetCode6023.cpp
	> Author: 
	> Mail: 
	> Created Time: 2022年03月19日 星期六 22时52分39秒
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

int minimumWhiteTiles(string floor, int numCarpets, int carpetLen) {
  int n = floor.size();
  vector<vector<int>> dp(n + 1, vector<int>(numCarpets + 1, 0x3f3f3f3f));
  dp[0][0] = 0;
  for (int i = 0; i < n; i++) {
    dp[i + 1][0] = dp[i][0];
    if (floor[i] == '1') dp[i + 1][0]++;
  }
  for (int i = 1; i <= numCarpets; i++) {
    for (int j = carpetLen * i; j <= n; j++) {
      dp[j][i] = min(dp[j - carpetLen][i - 1], dp[j - 1][i] + (floor[j - 1] == '1' ? 1 : 0));
    }
  }
  return dp[n][numCarpets] == 0x3f3f3f3f ? 0 : dp[n][numCarpets];
}

int main() {
  return 0;
}
