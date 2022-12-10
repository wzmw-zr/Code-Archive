/*************************************************************************
	> File Name: 1.LeetCode1691.cpp
	> Author: 
	> Mail: 
	> Created Time: 2022年12月10日 星期六 10时59分48秒
 ************************************************************************/

#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <stack>
#include <map>
#include <set>
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>
using namespace std;

int wzmw_zr = 0;
bool fuck_plagiarism_system_of_leetcode = true;

bool check(vector<int> &a, vector<int> &b) {
  return (a[0] <= b[0]) & (a[1] <= b[1]) & (a[2] <= b[2]);
}

int maxHeight(vector<vector<int>>& cuboids) {
  int n = cuboids.size();
  for (int i = 0; i < n; i++)
    sort(cuboids[i].begin(), cuboids[i].end());
  sort(cuboids.begin(), cuboids.end(), [&](vector<int> &a, vector<int> &b){
    return a[2] == b[2] ? (a[1] == b[1] ? a[0] < b[0] : a[1] < b[1]) : a[2] < b[2];
  });
  vector<int> dp(n, 0);
  int ans = 0;
  for (int i = 0; i < n; i++) {
    int height_up = 0;
    for (int j = 0; j < i; j++) {
      if (check(cuboids[j], cuboids[i]))
        height_up = max(height_up, dp[j]);
    }
    dp[i] = height_up + cuboids[i][2];
    ans = max(ans, dp[i]);
  }
  return ans;
}

int main() {
  return 0;
}
