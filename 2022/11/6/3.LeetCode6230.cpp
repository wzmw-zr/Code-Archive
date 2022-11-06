/*************************************************************************
	> File Name: 3.LeetCode6230.cpp
	> Author: 
	> Mail: 
	> Created Time: 2022年11月06日 星期日 10时35分42秒
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

long long maximumSubarraySum(vector<int>& nums, int k) {
  long long ans = 0;
  long long sum = 0;
  int n = nums.size();
  int left = 0, right = 0;
  unordered_map<int, int> mp;
  while (right < n) {
    sum += nums[right];
    mp[nums[right]]++;
    right++;
    if (right - left == k) {
      if (mp.size() == k) 
        ans = max(ans, sum);
      sum -= nums[left];
      if (!(--mp[nums[left]]))
        mp.erase(nums[left]);
      left++;
    }
  }
  return ans;
}

int main() {
  return 0;
}
