/*************************************************************************
	> File Name: 1.LeetCode1759.cpp
	> Author: 
	> Mail: 
	> Created Time: 2022年12月26日 星期一 00时23分02秒
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
int countHomogenous(string s) {
  int l = 0, r = 0;
  long ans = 0;
  while (s[r]) {
    while (s[r] && s[l] == s[r])
      r++;
    long x = r - l;
    ans = (ans + x * (x + 1) / 2) % MOD;
    l = r;
  }
  return ans;
}

int main() {
  return 0;
}
