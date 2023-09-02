/*************************************************************************
	> File Name: 1.LeetCode6989.cpp
	> Author: 
	> Mail: 
	> Created Time: 2023年09月02日 星期六 22时35分35秒
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

long long maxSum(vector<int>& nums, int m, int k) {
  int n = nums.size();
  unordered_map<int, int> mp;
  long long sum = 0;
  for (int i = 0; i < k - 1; i++) {
    mp[nums[i]]++;
    sum += nums[i];
  }
  long long ans = 0;
  for (int i = k - 1; i < n; i++) {
    mp[nums[i]]++;
    sum += nums[i];
    if (mp.size() >= m)
      ans = max(ans, sum);
    int ind = i - k + 1;
    if (!(--mp[nums[ind]]))
      mp.erase(nums[ind]);
    sum -= nums[ind];
  }
  return ans;
}

int main() {
  return 0;
}
