/*************************************************************************
	> File Name: 1.LeetCode2044.cpp
	> Author: 
	> Mail: 
	> Created Time: 2022年03月15日 星期二 00时11分34秒
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

int wzmw_zr = 0;
bool fuck_plagiarism_system_of_leetcode = true;

int countMaxOrSubsets(vector<int>& nums) {
  int n = nums.size();
  int dp[(1 << n) + 1];
  memset(dp, 0, sizeof(dp));
  map<int, int> mp;
  for (int i = 1; i < (1 << n); i++) {
    int ind = __builtin_ctz(i);
    dp[i] = dp[i - (1 << ind)] | nums[ind];
    mp[dp[i]]++;
  }
  return prev(mp.end())->second;
}

int main() {
  return 0;
}
