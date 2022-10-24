/*************************************************************************
	> File Name: 1.LeetCode915.cpp
	> Author: 
	> Mail: 
	> Created Time: 2022年10月24日 星期一 09时54分09秒
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

int partitionDisjoint(vector<int>& nums) {
  int n = nums.size();
  vector<int> left(n, 0);
  vector<int> right(n, 0);
  left[0] = nums[0], right[n - 1] = nums[n - 1];
  for (int i = 1; i < n; i++)
    left[i] = max(left[i - 1], nums[i]);
  for (int i = n - 2; i >= 0; i--) 
    right[i] = min(right[i + 1], nums[i]);
  for (int i = 0; i < n - 1; i++) {
    if (left[i] <= right[i + 1])
      return i + 1;
  }
  return -1;
}

int main() {
  return 0;
}
