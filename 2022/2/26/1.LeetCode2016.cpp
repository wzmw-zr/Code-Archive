/*************************************************************************
	> File Name: 1.LeetCode2016.cpp
	> Author: 
	> Mail: 
	> Created Time: 2022年02月26日 星期六 00时04分21秒
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

int maximumDifference(vector<int>& nums) {
  int ans = -1;
  int n = nums.size();
  int mmax = INT32_MIN;
  for (int i = n - 1; i >= 0; i--) {
    if (mmax > nums[i]) 
      ans = max(ans, mmax - nums[i]);
    mmax = max(mmax, nums[i]);
  }
  return ans;
}

int main() {
  return 0;
}
