/*************************************************************************
	> File Name: 1.LeetCode2681.cpp
	> Author: 
	> Mail: 
	> Created Time: 2023年08月01日 星期二 09时53分23秒
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
  long ans = 0;
  long pre = 0;
  sort(nums.begin(), nums.end());
  for (int x : nums) {
    ans = (ans + ((pre + x) * x % MOD) * x % MOD) % MOD;
    pre = (pre * 2 + x) % MOD;
  }
  return ans;
}

int main() {
  return 0;
}
