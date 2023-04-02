/*************************************************************************
	> File Name: 2.LeetCode6327.cpp
	> Author: 
	> Mail: 
	> Created Time: 2023年04月01日 星期六 22时31分02秒
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

int minNumber(vector<int>& nums1, vector<int>& nums2) {
  sort(nums1.begin(), nums1.end());
  sort(nums2.begin(), nums2.end());
  unordered_set<int> st1(nums1.begin(), nums1.end());
  for (int x : nums2) {
    if (st1.count(x))
      return x;
  }
  if (nums1[0] < nums2[0])
    return nums1[0] * 10 + nums2[0];
  return nums2[0] * 10 + nums1[0];
}

int main() {
  return 0;
}
