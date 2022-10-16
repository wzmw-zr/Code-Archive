/*************************************************************************
	> File Name: 5.LeetCode6210.cpp
	> Author: 
	> Mail: 
	> Created Time: 2022年10月15日 星期六 23时06分09秒
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

bool check(vector<long> nums, int val) {
  int n = nums.size();
  for (int i = n - 1; i >= 1; i--) {
    if (nums[i] > val) {
      nums[i - 1] += nums[i] - val;
      nums[i] = val;
    }
  }
  return nums[0] <= val;
}

int minimizeArrayValue(vector<int>& nums) {
  int l = 0, r = 1e9;
  vector<long> temp(nums.begin(), nums.end());
  while (l < r) {
    int mid = (l + r) / 2;
    if (check(temp, mid))
      r = mid;
    else
      l = mid + 1;
  }
  return l;
}

int main() {
  return 0;
}
