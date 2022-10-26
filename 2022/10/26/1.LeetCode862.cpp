/*************************************************************************
	> File Name: 1.LeetCode862.cpp
	> Author: 
	> Mail: 
	> Created Time: 2022年10月26日 星期三 10时23分48秒
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

int shortestSubarray(vector<int>& nums, int k) {
  int n = nums.size();
  vector<long> pre(n + 1, 0);
  for (int i = 0; i < n; i++)
    pre[i + 1] = pre[i] + nums[i];
  deque<int> que;
  que.push_back(0);
  int ans = INT32_MAX;
  for (int i = 1; i <= n; i++) {
    while (!que.empty() && pre[que.front()] <= pre[i] - k) {
      ans = min(ans, i - que.front());
      que.pop_front();
    }
    while (!que.empty() && pre[que.back()] >= pre[i]) 
      que.pop_back();
    que.push_back(i);
  }
  return ans == INT32_MAX ? -1 : ans;
}

int main() {
  return 0;;
}
