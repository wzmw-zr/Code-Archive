/*************************************************************************
	> File Name: 1.LeetCode1031.cpp
	> Author: 
	> Mail: 
	> Created Time: 2023年04月26日 星期三 09时15分48秒
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
#include <cstring>
#include <cstdlib>
using namespace std;

int wzmw_zr = 0;
bool fuck_plagiarism_system_of_leetcode = true;

int maxSumTwoNoOverlap(vector<int>& nums, int firstLen, int secondLen) {
  int n = nums.size();
  int pre[n + 1];
  memset(pre, 0, sizeof(pre));
  for (int i = 0; i < n; i++)
    pre[i + 1] = pre[i] + nums[i];

  int dp1[n + 1], dp2[n + 1];
  memset(dp1, 0, sizeof(dp1));
  memset(dp2, 0, sizeof(dp2));

  for (int i = firstLen; i <= n; i++)
    dp1[i] = max(dp1[i - 1], pre[i] - pre[i - firstLen]);

  for (int i = secondLen; i <= n; i++)
    dp2[i] = max(dp2[i - 1], pre[i] - pre[i - secondLen]);

  int ans = 0;
  for (int i = firstLen + secondLen; i <= n; i++) {
    ans = max(ans, pre[i] - pre[i - firstLen] + dp2[i - firstLen]);
    ans = max(ans, pre[i] - pre[i - secondLen] + dp1[i - secondLen]);
  }
  return ans;
}

int main() {
  return 0;
}
