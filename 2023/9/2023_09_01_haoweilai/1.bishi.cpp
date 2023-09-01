/*************************************************************************
	> File Name: 1.bishi.cpp
	> Author: 
	> Mail: 
	> Created Time: 2023年09月01日 星期五 19时12分03秒
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
#include <cstdint>
using namespace std;

int main() {
  string s1, s2;
  cin >> s1 >> s2;
  int n = s1.size(), m = s2.size();
  vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      if (s1[i] == s2[j]) {
        dp[i + 1][j + 1] = dp[i][j] + 1;
      } else {
        dp[i + 1][j + 1] = max(dp[i + 1][j], dp[i][j + 1]);
      }
    }
  }
  cout << max(n, m) - dp[n][m] << endl;
  return 0;
}
