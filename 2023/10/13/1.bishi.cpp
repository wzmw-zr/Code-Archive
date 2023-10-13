/*************************************************************************
	> File Name: 1.bishi.cpp
	> Author: 
	> Mail: 
	> Created Time: 2023年10月13日 星期五 19时22分12秒
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


int main() {
  string s;
  getline(cin, s);
  vector<int> prices;
  int ind = 0;
  while (s[ind]) {
    string str = "";
    while (s[ind] && s[ind] != ',')
      str += s[ind++];
    if (s[ind] == ',')
      ind++;
    prices.push_back(stoi(str));
  }
  int n = prices.size();
  int ans = 0;
  vector<vector<int>> dp(n + 10, vector<int>(5, 0));
  for (int i = 1; i <= n; i++) {
    int mmin = prices[i - 1];
    for (int j = i - 1; j >= 0; j--) {
      mmin = min(mmin, prices[j]);
      for (int k = 1; k <= 3; k++) {
        dp[i][k] = max(dp[i][k], dp[j][k - 1] + prices[i - 1] - mmin);
        ans = max(ans, dp[i][k]);
      }
    }
  }
  cout << ans << endl;
  return 0;
}
