/*************************************************************************
	> File Name: 1.LeetCode2488.cpp
	> Author: 
	> Mail: 
	> Created Time: 2023年03月16日 星期四 09时23分29秒
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

int countSubarrays(vector<int>& nums, int k) {
  int n = nums.size();
  int ind = 0;
  while (nums[ind] != k)
    ind++;
  unordered_map<int, int> left;
  left[0] = 1;
  int x = 0, y = 0;
  for (int i = ind - 1; i >= 0; i--) {
    x += nums[i] < k ? 1 : 0;
    y += nums[i] > k ? 1 : 0;
    left[x - y]++;
  }
  x = 0, y = 0;
  int ans = 0;
  for (int i = ind + 1; i < n; i++) {
    x += nums[i] < k ? 1 : 0;
    y += nums[i] > k ? 1 : 0;
    ans += left.count(y - x) ? left[y - x] : 0;
    ans += left.count(y - x - 1) ? left[y - x - 1] : 0;
  }
  return ans;
}

int main() {
  return 0;
}
