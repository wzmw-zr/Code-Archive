/*************************************************************************
	> File Name: 1.LeetCode7006.cpp
	> Author: 
	> Mail: 
	> Created Time: 2023年08月20日 星期日 10时40分30秒
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

int maximizeTheProfit(int n, vector<vector<int>>& offers) {
  vector<int> dp(n + 1, 0);
  sort(offers.begin(), offers.end(), [](vector<int> &a, vector<int> &b){
    return a[1] < b[1];
  });
  vector<vector<int>> inds(n + 1);
  for (int i = 0; i < offers.size(); i++) {
    int start = offers[i][0];
    int end = offers[i][1];
    inds[end + 1].push_back(i);
  }
  int ans = 0;
  for (int i = 1; i <= n; i++) {
    dp[i] = dp[i - 1];
    for (int ind : inds[i]) {
      int start = offers[ind][0], end = offers[ind][1], val = offers[ind][2];
      dp[end + 1] = max(dp[end + 1], dp[start] + val);
    }
    ans = max(ans, dp[i]);
  }
  return ans;
}

int main() {
  return 0;
}
