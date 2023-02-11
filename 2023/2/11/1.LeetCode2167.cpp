/*************************************************************************
	> File Name: 1.LeetCode2167.cpp
	> Author: 
	> Mail: 
	> Created Time: 2023年02月11日 星期六 10时06分40秒
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

int minimumTime(string s) {
  int n = s.size();
  vector<int> dp1(n + 1, 0), dp2(n + 1, 0);
  for (int i = 0; i < n; i++) {
    if (s[i] == '0')
      dp1[i + 1] = dp1[i];
    else
      dp1[i + 1] = min({dp1[i] + 2, i + 1});
  }
  for (int i = n - 1; i >= 0; i--) {
    if (s[i] == '0')
      dp2[i] = dp2[i + 1];
    else
      dp2[i] = min({dp2[i + 1] + 2, n - i});
  }
  int ans = INT32_MAX;
  for (int i = 0; i < n; i++) 
    ans = min(ans, dp1[i + 1] + dp2[i + 1]);
  return ans;
}

int main() {
  return 0;
}
