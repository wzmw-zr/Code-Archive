/*************************************************************************
	> File Name: 5.LeetCode5229.cpp
	> Author: 
	> Mail: 
	> Created Time: 2022年06月26日 星期日 10时43分34秒
 ************************************************************************/

#include <iostream>
#include <string>
#include <vector>
#include <stack>
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

int maximumsSplicedArray(vector<int>& nums1, vector<int>& nums2) {
  int n = nums1.size();
  vector<int> dp1(n, INT32_MAX);
  vector<int> dp2(n, INT32_MIN);
  dp1[0] = min(dp1[0], nums2[0] - nums1[0]);
  dp2[0] = max(dp2[0], nums2[0] - nums1[0]);
  for (int i = 1; i < n; i++) {
    dp1[i] = min(dp1[i - 1] + nums2[i]  - nums1[i], nums2[i] - nums1[i]);
    dp2[i] = max(dp2[i - 1] + nums2[i]  - nums1[i], nums2[i] - nums1[i]);
  }
  int mmin = 0;
  int mmax = 0;
  int sum1 = 0;
  int sum2 = 0;
  for (int i = 0; i < n; i++) {
    mmin = min(mmin, dp1[i]);
    mmax = max(mmax, dp2[i]);
    sum1 += nums1[i];
    sum2 += nums2[i];
  }
  return max(sum1 + mmax, sum2 - mmin);
}

int main() {
  return 0;
}
