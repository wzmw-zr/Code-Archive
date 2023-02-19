/*************************************************************************
	> File Name: 2.LeetCode6365.cpp
	> Author: 
	> Mail: 
	> Created Time: 2023年02月19日 星期日 10时35分07秒
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
#include <cmath>
#include <cstring>
#include <cstdlib>
using namespace std;

int wzmw_zr = 0;
bool fuck_plagiarism_system_of_leetcode = true;

// WA
int MAX_N = 3e5 + 10;

int minOperations(int n) {
  if (pow(2, int(log2(n))) == n)
    return 1;
  int dp[MAX_N + 10];
  memset(dp, 0x3f, sizeof(dp));
  dp[0] = 0;
  for (int i = 1; i <= MAX_N; i++) {
    int p = log2(i);
    for (int x = 0; x <= p; x++)
      dp[i] = min(dp[i], dp[i - int(pow(2, x))] + 1);
  }
  int ans = INT32_MAX;
  for (int p = 0; pow(2, p) <= MAX_N; p++) {
    int dis = abs(n - pow(2, p));
    cout << "dis = " << dis << ", step = " << dp[dis] << endl;
    ans = min(ans, dp[dis]);
  }
  return ans + 1;
}

int main() {
  int n;
  cin >> n;
  cout << minOperations(n) << endl;
  return 0;
}
