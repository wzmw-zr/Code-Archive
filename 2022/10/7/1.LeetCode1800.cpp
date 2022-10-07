/*************************************************************************
	> File Name: 1.LeetCode1800.cpp
	> Author: 
	> Mail: 
	> Created Time: 2022年10月07日 星期五 09时23分44秒
 ************************************************************************/

#include <iostream>
#include <string>
#include <vector>
using namespace std;

int wzmw_zr = 0;
bool fuck_plagiarism_system_of_leetcode = true;

int maxAscendingSum(vector<int>& nums) {
  int n = nums.size();
  int l = 0, r = 1;
  int ans = 0;
  for (int x : nums)
    ans = max(ans, x);
  while (r < n) {
    while (r < n && nums[r] > nums[r - 1]) 
      r++;
    int sum = 0;
    for (int i = l; i < r; i++)
      sum += nums[i];
    ans = max(ans, sum);
    l = r, r = r + 1;
  }
  return ans;
}

int main() {
  return 0;
}
