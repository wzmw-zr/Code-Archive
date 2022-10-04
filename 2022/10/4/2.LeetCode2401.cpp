/*************************************************************************
	> File Name: 2.LeetCode2401.cpp
	> Author: 
	> Mail: 
	> Created Time: 2022年10月04日 星期二 11时00分03秒
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

int longestNiceSubarray(vector<int>& nums) {
  int n = nums.size();
  int l = 0, r = 0;
  int val = 0;
  int ans = 1;
  while (r < n) {
    while (r < n && !(val & nums[r])) 
      val += nums[r++];
    ans = max(ans, r - l);
    if (r == n)
      break;
    while (l < r && (val & nums[r]))
      val -= nums[l++];
  }
  return ans;
}

int main() {
  return 0;
}
