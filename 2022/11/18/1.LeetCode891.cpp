/*************************************************************************
	> File Name: 1.LeetCode891.cpp
	> Author: 
	> Mail: 
	> Created Time: 2022年11月18日 星期五 22时52分48秒
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

long qpow(long x, long p) {
  long base = x;
  long ans = 1;
  while (p) {
    if (p & 1)
      ans = (ans * base) % MOD;
    base = (base * base) % MOD;
    p >>= 1;
  }
  return ans;
}

int sumSubseqWidths(vector<int>& nums) {
  int n = nums.size();
  sort(nums.begin(), nums.end());
  long ans = 0;
  for (int i = 0; i < n; i++)
    ans = ((ans + 1L * nums[i] * (qpow(2, i) - qpow(2, n - 1 - i))) % MOD + MOD) % MOD;
  return ans;
}

int main() {
  return 0;
}
