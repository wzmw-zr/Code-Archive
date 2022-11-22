/*************************************************************************
	> File Name: 1.LeetCode878.cpp
	> Author: 
	> Mail: 
	> Created Time: 2022年11月22日 星期二 10时04分25秒
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
using namespace std;

int wzmw_zr = 0;
bool fuck_plagiarism_system_of_leetcode = true;

long MOD = 1e9 + 7;

long gcd(long a, long b) {
  return b == 0 ? a : gcd(b, a % b);
}

int nthMagicalNumber(int n, int a, int b) {
  long x = a, y = b;
  long lcm = x * y / gcd(x, y);
  long l = 1, r = min(x, y) * n;
  while (l < r) {
    long mid = (l + r) / 2;
    long cnt = mid / x + mid / y - mid / lcm;
    if (cnt >= n)
      r = mid;
    else
      l = mid + 1;
  }
  return l % MOD;
}

int main() {
  return 0;
}
