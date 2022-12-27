/*************************************************************************
	> File Name: 2.LeetCode2514.cpp
	> Author: 
	> Mail: 
	> Created Time: 2022年12月27日 星期二 10时52分52秒
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

long MOD = 1e9 + 7;

long factorial(long x) {
  long ans = 1;
  for (long i = 1; i <= x; i++)
    ans = ans * i % MOD;
  return ans;
}

long qpow(long x, long p) {
  long ans = 1;
  while (p) {
    if (p & 1)
      ans = ans * x % MOD;
    x = x * x % MOD;
    p >>= 1;
  }
  return ans;
}

int countAnagrams(string s) {
  int n = s.size();
  int ind = 0;
  long a = 1, b = 1;
  while (s[ind]) {
    int cnt = 0;
    vector<int> cnts(26, 0);
    while (s[ind] && s[ind] != ' ') {
      cnts[s[ind] - 'a']++;
      ind++;
      cnt++;
    }
    a = a * factorial(cnt) % MOD;
    for (int x : cnts)
      b = b * factorial(x) % MOD;
    if (s[ind])
      ind++;
  }
  return a * qpow(b, MOD - 2) % MOD;
}

int main() {
  return 0;
}
