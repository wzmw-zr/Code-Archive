/*************************************************************************
	> File Name: 3.mianshi.cpp
	> Author: 
	> Mail: 
	> Created Time: 2023年07月23日 星期日 19时55分20秒
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
  int t;
  cin >> t;
  for (int j = 0; j < t; j++) {
    long n, x;
    cin >> n >> x;
    vector<long> nums(n);
    for (int i = 0; i < n; i++)
      cin >> nums[i];
    vector<vector<long>> dp(n + 1, vector<long>(2, INT32_MIN));
    long ans = INT32_MIN;
    for (int i = 0; i < n; i++) {
      dp[i + 1][0] = max({dp[i][0] + nums[i], nums[i]});
      dp[i + 1][1] = max({dp[i][0] + x, dp[i][1] + nums[i], x});
      ans = max({ans, dp[i + 1][0], dp[i + 1][1]});
    }
    cout << ans << endl;
  }
  return 0;
}
