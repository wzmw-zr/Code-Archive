/*************************************************************************
	> File Name: 3.mianshi.cpp
	> Author: 
	> Mail: 
	> Created Time: 2023年04月23日 星期日 17时13分32秒
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

long MOD = 1e9 + 7;

long qpow(int b, int p) {
  long ans = 1;
  long base = b;
  while (p) {
    if (p & 1)
      ans = (ans * base) % MOD;
    base = (base * base) % MOD;
    p >>= 1;
  }
  return ans;
}

int main() {
  int n;
  cin >> n;
  long dp[n + 10][3];
  memset(dp, 0, sizeof(dp));
  for (int i = 1; i <= n; i++) {
    dp[i][0] = (dp[i - 1][0] * 3 + qpow(3, i - 1)) % MOD;
    if (i >= 2) {
      dp[i][1] = (dp[i - 1][1] * 3 + dp[i - 1][0]) % MOD;
    }
    if (i >= 3) {
      dp[i][2] = (dp[i - 1][2] * 3 + dp[i - 1][1]) % MOD;
    }
  }

  long dp2[n + 10];
  memset(dp2, 0, sizeof(dp2));
  for (int i = 3; i <= n; i++) {
    for (int j = 3; j <= i; j++) {
      dp2[i] = (dp2[i] + dp[j][2] * (i - j + 1) % MOD) % MOD;
    }
  }
  cout << dp2[n] << endl;
  return 0;
}
