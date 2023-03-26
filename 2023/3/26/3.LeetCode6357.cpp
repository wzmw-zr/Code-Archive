/*************************************************************************
	> File Name: 3.LeetCode6357.cpp
	> Author: 
	> Mail: 
	> Created Time: 2023年03月26日 星期日 11时06分08秒
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

vector<long long> minOperations(vector<int>& nums, vector<int>& queries) {
  int n = nums.size(), m = queries.size();
  sort(nums.begin(), nums.end());
  vector<long long> pre(n + 1, 0);
  for (int i = 0; i < n; i++)
    pre[i + 1] = pre[i] + nums[i];

  vector<long long> ans;
  for (int q : queries) {
    int l = -1, r = n - 1;
    while (l < r) {
      int mid = (l + r + 1) / 2;
      if (nums[mid] <= q)
        l = mid;
      else
        r = mid - 1;
    }
    long long val = (1L * q * (l + 1) - pre[l + 1]) + (pre[n] - pre[l + 1] - 1L * q * (n - l - 1));
    ans.push_back(val);
  }
  return ans;
}

int main() {
  return 0;
}
