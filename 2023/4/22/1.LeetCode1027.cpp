/*************************************************************************
	> File Name: 1.LeetCode1027.cpp
	> Author: 
	> Mail: 
	> Created Time: 2023年04月22日 星期六 09时24分06秒
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

int longestArithSeqLength(vector<int>& nums) {
  int n = nums.size();
  vector<unordered_map<int, int>> dp(510);
  int ans = 2;
  for (int i = 0; i < n; i++) {
    if (!dp[nums[i]].count(0))
      dp[nums[i]][0] = 1;
    int flag = 0;
    for (int j = 0; j < i; j++) {
      int dis = nums[i] - nums[j];
      if (dis == 0) {
        flag = 1;
      } else {
        if (dp[nums[j]].count(dis))
          dp[nums[i]][dis] = dp[nums[j]][dis] + 1;
        else
          dp[nums[i]][dis] = 2;
        ans = max(ans, dp[nums[i]][dis]);
      }
    }
    if (flag) {
      dp[nums[i]][0]++;
      ans = max(ans, dp[nums[i]][0]);
    }
  }
  return ans;
}

int main() {
  return 0;
}
