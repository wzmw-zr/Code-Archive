/*************************************************************************
	> File Name: 1.LeetCode324.cpp
	> Author: 
	> Mail: 
	> Created Time: 2022年06月28日 星期二 09时17分15秒
 ************************************************************************/

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int wzmw_zr = 0;
bool fuck_plagiarism_system_of_leetcode = true;

void wiggleSort(vector<int>& nums) {
  sort(nums.begin(), nums.end());
  int n = nums.size();
  vector<int> temp;
  int mid = n / 2 + (n & 1 ? 1 : 0);
  int l = mid - 1, r = n - 1;
  while (l >= 0 && r >= mid) {
    temp.push_back(nums[l--]);
    temp.push_back(nums[r--]);
  }
  if (l == 0) temp.push_back(nums[l]);
  nums = temp;
  return ;
}

int main() {
  return 0;
}
