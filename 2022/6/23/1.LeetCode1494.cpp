/*************************************************************************
	> File Name: 1.LeetCode1494.cpp
	> Author: 
	> Mail: 
	> Created Time: 2022年06月23日 星期四 16时46分11秒
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

int minNumberOfSemesters(int n, vector<vector<int>>& relations, int k) {
  int pre_req[n];
  memset(pre_req, 0, sizeof(pre_req));
  for (auto && relation : relations) {
    int x = relation[0], y = relation[1];
    pre_req[y - 1] |= (1 << (x - 1));
  }
  int set_req[(1 << n)], valid[(1 << n)];
  memset(set_req, 0, sizeof(set_req));
  memset(valid, 0, sizeof(valid));
  for (int i = 0; i < (1 << n); i++) {
    if (__builtin_popcount(i) <= k) {
      int mask = 0;
      for (int j = 0; j < n; j++) {
        if (i & (1 << j)) mask |= pre_req[j];
      }
      if ((mask & i) == 0) {
        set_req[i] = mask;
        valid[i] = 1;
      }
    }
  }
  int dp[1 << n];
  memset(dp, 0x3f, sizeof(dp));
  for (int i = 1; i < (1 << n); i++) {
    if (valid[i] && set_req[i] == 0) dp[i] = 1;
    for (int j = i; j > 0; j = (j - 1) & i) {
      if (valid[j] && (((i - j) & set_req[j]) == set_req[j])) {
        dp[i] = min(dp[i], dp[i - j] + 1);
      }
    }
  }
  return dp[(1 << n) - 1];
}

int main() {
  return 0;
}
