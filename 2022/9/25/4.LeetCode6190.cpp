/*************************************************************************
	> File Name: 4.LeetCode6190.cpp
	> Author: 
	> Mail: 
	> Created Time: 2022年09月25日 星期日 10时49分45秒
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

vector<int> goodIndices(vector<int>& nums, int k) {
  int n = nums.size();
  vector<int> pre(n, 1);
  vector<int> suf(n, 1);
  for (int i = 1; i < n; i++) {
    if (nums[i] <= nums[i - 1])
      pre[i] = pre[i - 1] + 1;
    else
      pre[i] = 1;
  }
  for (int i = n - 2; i >= 0; i--) {
    if (nums[i] <= nums[i + 1]) 
      suf[i] = suf[i + 1] + 1;
    else
      suf[i] = 1;
  }
  vector<int> ans;
  for (int i = k; i < n - k; i++) {
    if (pre[i - 1] >= k && suf[i + 1] >= k)
      ans.push_back(i);
  }
  return ans;
}

int main() {
  return 0;
}
