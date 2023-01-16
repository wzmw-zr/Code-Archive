/*************************************************************************
	> File Name: 1.LeetCode1814.cpp
	> Author: 
	> Mail: 
	> Created Time: 2023年01月17日 星期二 00时30分45秒
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

int countNicePairs(vector<int>& nums) {
  unordered_map<long, long> mp;
  for (int x : nums) {
    string s = to_string(x);
    reverse(s.begin(), s.end());
    long rev = stol(s);
    mp[1L * x - rev]++;
  }
  long ans = 0;
  for (auto && [x, cnt] : mp)
    ans = (ans + cnt * (cnt - 1) / 2) % MOD;
  return ans;
}

int main() {
  return 0;
}
