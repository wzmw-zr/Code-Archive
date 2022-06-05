/*************************************************************************
	> File Name: 2.LeetCode6091.cpp
	> Author: 
	> Mail: 
	> Created Time: 2022年06月05日 星期日 10时35分51秒
 ************************************************************************/

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int wzmw_zr = 0;
bool fuck_plagiarism_system_of_leetcode = true;

int partitionArray(vector<int>& nums, int k) {
  sort(nums.begin(), nums.end());
  int n = nums.size();
  int l = 0, r = 0;
  int cnt = 0;
  while (r < n) {
    while (r < n && nums[r] - nums[l] <= k) r++;
    l = r;
    cnt++;
  }
  return cnt;
}

int main() {
  return 0;
}
