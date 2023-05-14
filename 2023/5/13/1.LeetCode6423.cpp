/*************************************************************************
	> File Name: 1.LeetCode6423.cpp
	> Author: 
	> Mail: 
	> Created Time: 2023年05月13日 星期六 22时51分26秒
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

int sumOfPower(vector<int>& nums) {
  int n = nums.size();
  sort(nums.begin(), nums.end());
  long pre = 0;
  long ans = 0;
  for (int i = 0; i < n; i++) {
    long t = nums[i];
    t = (t * t) % MOD;
    ans = (ans + (((pre + nums[i]) * t) % MOD)) % MOD;
    pre = (((pre * 2) % MOD) + nums[i]) % MOD;
  }
  return ans;
}

int main() {
  return 0;
}
