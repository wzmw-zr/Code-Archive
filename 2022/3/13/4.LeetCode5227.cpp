/*************************************************************************
	> File Name: 4.LeetCode5227.cpp
	> Author: 
	> Mail: 
	> Created Time: 2022年03月13日 星期日 10时56分12秒
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

int maximumTop(vector<int>& nums, int k) {
  int n = nums.size();
  if (n == 1 && (k & 1)) return -1;
  int mmax = INT32_MIN;
  for (int i = 0; i < min(n, k - 1); i++) mmax = max(nums[i], mmax);
  if (k < n) mmax = max(mmax, nums[k]);
  return mmax;
}

int main() {
  return 0;
}
