/*************************************************************************
	> File Name: 3.mianshi.cpp
	> Author: 
	> Mail: 
	> Created Time: 2023年04月15日 星期六 21时27分41秒
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

long MOD = 1e9 + 7;

long Frac(long x) {
  long ans = 1;
  for (long i = 1; i <= x; i++)
    ans = (ans * i) % MOD;
  return ans;
}

long qpow(long b, long p) {
  long ans = 1;
  long base = b;
  while (p) {
    if (p & 1) {
      ans = (ans * base) % MOD;
    }
    base = base * base % MOD;
    p >>= 1;
  }
  return ans;
}

long CBN(long x, long y) {
  long a = Frac(x);
  long b = Frac(x - y) * Frac(y) % MOD;
  return (a * qpow(b, MOD - 2)) % MOD;
}

long Numsubsequence(vector<int> &nums, int k) {
  unordered_map<int, int> mp;
  for (int x : nums)
    mp[x]++;
  long ans = 1;
  for (auto && [x, cnt] : mp) {
    long num_methods = 1;
    for (int i = k; i <= cnt; i += k)
      num_methods = (num_methods + CBN(cnt, i)) % MOD;
    ans = (ans * num_methods) % MOD;
  }
  return ans - 1;
}

int main() {
  int n, k;
  cin >> n >> k;
  vector<int> a(n);
  for (int i = 0; i < n; i++)
    cin >> a[i];
  cout << Numsubsequence(a, k) << endl;
  return 0;
}
