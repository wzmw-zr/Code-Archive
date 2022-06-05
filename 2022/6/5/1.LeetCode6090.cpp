/*************************************************************************
	> File Name: 1.LeetCode6090.cpp
	> Author: 
	> Mail: 
	> Created Time: 2022年06月05日 星期日 10时30分51秒
 ************************************************************************/

#include <iostream>
#include <string>
#include <vector>
using namespace std;

int wzmw_zr = 0;
bool fuck_plagiarism_system_of_leetcode = true;

int minMaxGame(vector<int>& nums) {
  while (nums.size() != 1) {
    int n = nums.size();
    vector<int> temp;
    for (int i = 0; i < n / 2; i++) {
      if (i & 1) 
        temp.push_back(max(nums[2 * i], nums[2 * i + 1]));
      else
        temp.push_back(min(nums[2 * i], nums[2 * i + 1]));
    }
    nums = temp;
  }
  return nums[0];
}

int main() {
  return 0;
}
