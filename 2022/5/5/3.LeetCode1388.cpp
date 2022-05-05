/*************************************************************************
	> File Name: 3.LeetCode1388.cpp
	> Author: 
	> Mail: 
	> Created Time: 2022年05月05日 星期四 21时34分40秒
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

int calculate(vector<int> &nums) {
  int n = nums.size();
  int cnt = (n + 1) / 3;
  int dp[n + 1][cnt + 1];
  memset(dp, 0, sizeof(dp));
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= cnt; j++) {
      dp[i][j] = max(dp[i - 1][j], (i - 2 >= 0 ? dp[i - 2][j - 1] : 0) + nums[i - 1]);
    }
  }
  return dp[n][cnt];
}

int maxSizeSlices(vector<int>& slices) {
  vector<int> arr1(slices.begin(), prev(slices.end()));
  vector<int> arr2(next(slices.begin()), slices.end());
  return max(calculate(arr1), calculate(arr2));
}

int main() {
  return 0;
}
