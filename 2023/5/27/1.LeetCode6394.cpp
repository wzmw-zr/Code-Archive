/*************************************************************************
	> File Name: 1.LeetCode6394.cpp
	> Author: 
	> Mail: 
	> Created Time: 2023年05月27日 星期六 22时33分57秒
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
#include <numeric>
using namespace std;

int minExtraChar(string s, vector<string>& dictionary) {
  int n = s.size();
  vector<int> dp(n + 1, 0);
  iota(dp.begin(), dp.end(), 0);
  unordered_set<string> st(dictionary.begin(), dictionary.end());
  for (int i = 1; i <= n; i++) {
    dp[i] = min(dp[i], dp[i - 1] + 1);
    for (int j = 1; j <= i; j++) {
      string str = s.substr(j - 1, i - j + 1);
      if (st.count(str))
        dp[i] = min(dp[i], dp[j - 1]);
    }
  }
  return dp[n];
}

int main() {
  return 0;
}
