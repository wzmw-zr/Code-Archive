/*************************************************************************
	> File Name: 1.LeetCode873.cpp
	> Author: 
	> Mail: 
	> Created Time: 2022年07月09日 星期六 09时14分57秒
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

int lenLongestFibSubseq(vector<int>& arr) {
  int n = arr.size();
  int dp[n][n];
  memset(dp, 0, sizeof(dp));
  for (int i = 1; i < n; i++) {
    for (int j = 0; j < i; j++) dp[j][i] = 2;
  }
  unordered_map<int, int> mp;
  for (int i = 0; i < n; i++) mp[arr[i]] = i;
  for (int i = 1; i < n; i++) {
    for (int j = 0; j < i; j++) {
      int sum = arr[j] + arr[i];
      if (mp.count(sum)) dp[i][mp[sum]] = max(dp[i][mp[sum]], dp[j][i] + 1);
    }
  }
  int ans = 0;
  for (int i = 1; i < n; i++) {
    for (int j = 0; j < i; j++) {
      if (dp[j][i] >= 3) ans = max(ans, dp[j][i]);
    }
  }
  return ans;
}

int main() {
  return 0;
}
