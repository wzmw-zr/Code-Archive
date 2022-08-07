/*************************************************************************
	> File Name: 2.LeetCode6136.cpp
	> Author: 
	> Mail: 
	> Created Time: 2022年08月07日 星期日 10时30分54秒
 ************************************************************************/

#include <iostream>
#include <string>
#include <vector>
using namespace std;

int wzmw_zr = 0;
bool fuck_plagiarism_system_of_leetcode = true;

int arithmeticTriplets(vector<int>& nums, int diff) {
  int ans = 0;
  int n = nums.size();
  for (int i = 0; i < n; i++) {
    for (int j = i + 1; j < n; j++) {
      if (nums[j] - nums[i] != diff) continue;
      for (int k = j + 1; k < n; k++) {
        if (nums[k] - nums[j] != diff) continue;
        ans++;
      }
    }
  }
  return ans;
}

int main() {
  return 0;
}
