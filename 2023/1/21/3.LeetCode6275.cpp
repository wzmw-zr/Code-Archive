/*************************************************************************
	> File Name: 3.LeetCode6275.cpp
	> Author: 
	> Mail: 
	> Created Time: 2023年01月21日 星期六 22时32分20秒
 ************************************************************************/

#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <stack>
#include <map>
#include <set>
#include <unordered_set>
#include <unordered_map>
#include <algorithm>
using namespace std;

int wzmw_zr = 0;
bool fuck_plagiarism_system_of_leetcode = true;

long long minOperations(vector<int>& nums1, vector<int>& nums2, int k) {
  int n = nums1.size();
  if (k == 0) {
    for (int i = 0; i < n; i++) {
      if (nums1[i] - nums2[i])
        return -1;
    }
    return 0;
  }
  long long diff = 0;
  long long abs_diff = 0;
  for (int i = 0; i < n; i++) {
    if ((nums1[i] - nums2[i]) % k)
      return -1;
    diff += nums1[i] - nums2[i];
    abs_diff += abs(nums1[i] - nums2[i]);
  }
  if (diff)
    return -1;
  return abs_diff / (2 * k);
}

int main() {
  return 0;
}
