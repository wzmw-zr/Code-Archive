/*************************************************************************
	> File Name: 3.LeetCode6189.cpp
	> Author: 
	> Mail: 
	> Created Time: 2022年09月25日 星期日 10时46分08秒
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

int longestSubarray(vector<int>& nums) {
  int mmax = nums[0];
  for (int x : nums)
    mmax = max(x, mmax);
  int max_len = 0;
  int len = 0;
  for (int x : nums) {
    if (x == mmax) 
      len++;
    else 
      len = 0;
    max_len = max(max_len, len);
  }
  return max_len;
}

int main() {
  return 0;
}
