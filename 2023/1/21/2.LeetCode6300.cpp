/*************************************************************************
	> File Name: 2.LeetCode6300.cpp
	> Author: 
	> Mail: 
	> Created Time: 2023年01月21日 星期六 22时30分38秒
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

int getCommon(vector<int>& nums1, vector<int>& nums2) {
  unordered_set<int> st1(nums1.begin(), nums1.end());
  for (int x : nums2) {
    if (st1.count(x))
      return x;
  }
  return -1;
}

int main() {
  return 0;
}
