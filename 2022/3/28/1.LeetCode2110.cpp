/*************************************************************************
	> File Name: 1.LeetCode2110.cpp
	> Author: 
	> Mail: 
	> Created Time: 2022年03月28日 星期一 00时16分01秒
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

long long getDescentPeriods(vector<int>& prices) {
  int n = prices.size();
  long long ans = 0;
  vector<int> dp(n, 1);
  for (int i = 1; i < n; i++) {
    if (prices[i] == prices[i - 1] - 1) dp[i] += dp[i - 1];
  }
  for (int i = 0; i < n; i++) ans += dp[i];
  return ans;
}

int main() {
  return 0;
}
