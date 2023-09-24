/*************************************************************************
	> File Name: 3.bishi.cpp
	> Author: 
	> Mail: 
	> Created Time: 2023年09月23日 星期六 14时17分08秒
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

long MOD = 1e9 + 7;

long qpow(long p, long q) {
  long base = p;
  long ans = 1;
  while (q) {
    if (q & 1)
      ans = (ans * base) % MOD;
    base = (base * base) % MOD;
    q >>= 1;
  }
  return ans;
}

long divisor(long p, long q) {
  return p * qpow(q, MOD - 2) % MOD;
}

int main() {
  int n;
  cin >> n;
  vector<int> nums(n);
  for (int i = 0; i < n; i++)
    cin >> nums[i];
  long sum = 0;
  for (int x : nums)
    sum = (sum + x) % MOD;
  vector<long> frac(n + 1, 1);
  for (int i = 2; i <= n; i++)
    frac[i] = (frac[i - 1] * i) % MOD;
  long ans = 0;
  for (int i = 1; i <= n; i++) {
    long p = divisor(frac[n], frac[n - i]) * divisor(frac[n], frac[i]) % MOD;
    p = sum * p % MOD;
    ans = (ans + p) % MOD;
  }
  long q = frac[n] * n % MOD;
  ans = divisor(ans, q);
  cout << ans << endl;
  return 0;
}
