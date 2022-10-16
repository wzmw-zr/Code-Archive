/*************************************************************************
	> File Name: 7.LeetCode6207.cpp
	> Author: 
	> Mail: 
	> Created Time: 2022年10月16日 星期日 15时05分34秒
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

long long countSubarrays(vector<int>& nums, int minK, int maxK) {
  int n = nums.size();
  int max_ind = -1, min_ind = -1, invalid_ind = -1;
  long ans = 0;
  for (int i = 0; i < n; i++) {
    if (nums[i] == minK)
      min_ind = i;
    if (nums[i] == maxK)
      max_ind = i;
    if (nums[i] < minK || nums[i] > maxK)
      invalid_ind = i;
    ans += max(min(min_ind, max_ind) - invalid_ind, 0);
  }
  return ans;
}

int main() {
  return 0;
}
