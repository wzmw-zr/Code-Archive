/*************************************************************************
	> File Name: 4.LeetCode6226.cpp
	> Author: 
	> Mail: 
	> Created Time: 2022年10月29日 星期六 22时44分41秒
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

int destroyTargets(vector<int>& nums, int space) {
  sort(nums.begin(), nums.end());
  unordered_map<int, int> mp_1;
  unordered_map<int, int> mp_2;
  for (int x : nums) {
    mp_1[x % space]++;
    if (!mp_2.count(x % space))
      mp_2[x % space] = x;
  }
  int mmax_cnt = 0;
  for (auto && [x, cnt] : mp_1) 
    mmax_cnt = max(mmax_cnt, cnt);
  int ans = INT32_MAX;
  for (auto && [x, cnt] : mp_1) {
    if (cnt == mmax_cnt)
      ans = min(ans, mp_2[x]);
  }
  return ans;
}

int main() {
  return 0;
}
