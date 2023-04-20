/*************************************************************************
	> File Name: 1.LeetCode1187.cpp
	> Author: 
	> Mail: 
	> Created Time: 2023年04月20日 星期四 14时27分15秒
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

int makeArrayIncreasing(vector<int>& arr1, vector<int>& arr2) {
  int n = arr1.size(), m = arr2.size();
  sort(arr2.begin(), arr2.end());
  int dp[n + 1][m + 1];
  memset(dp, 0x3f, sizeof(dp));
  dp[0][0] = arr1[0], dp[0][1] = arr2[0];
  for (int i = 1; i < n; i++) {
    for (int j = 0; j <= min(i + 1, m); j++) {
      if (arr1[i] > dp[i - 1][j]) {
        dp[i][j] = min(dp[i][j], arr1[i]);
      }
      if (j > 0) {
        int l = 0, r = m - 1;
        while (l < r) {
          int mid = (l + r) / 2;
          if (arr2[mid] <= dp[i - 1][j - 1])
            l = mid + 1;
          else
            r = mid;
        }
        if (arr2[l] > dp[i - 1][j - 1]) {
          dp[i][j] = min(dp[i][j], arr2[l]);
        }
      }
    }
  }
  for (int i = 0; i <= m; i++) {
    if (dp[n - 1][i] != 0x3f3f3f3f)
      return i;
  }
  return -1;
}

int main() {
  return 0;
}
