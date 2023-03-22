/*************************************************************************
	> File Name: 1.LeetCode1626.cpp
	> Author: 
	> Mail: 
	> Created Time: 2023年03月22日 星期三 09时18分28秒
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

int bestTeamScore(vector<int>& scores, vector<int>& ages) {
  int n = scores.size();
  vector<int> inds(n);
  for (int i = 0; i < n; i++)
    inds[i] = i;
  sort(inds.begin(), inds.end(), [&](int x, int y){
    return ages[x] == ages[y] ? scores[x] < scores[y] : ages[x] < ages[y];
  });
  vector<int> dp(n + 1);
  for (int i = 0; i < n; i++)
    dp[i] = scores[inds[i]];
  int ans = dp[0];
  for (int i = 1; i < n; i++) {
    int x = inds[i];
    for (int j = 0; j < i; j++) {
      int y = inds[j];
      if (ages[y] < ages[x] && scores[y] > scores[x])
        continue;
      dp[i] = max(dp[i], dp[j] + scores[x]);
    }
    ans = max(ans, dp[i]);
  }
  return ans;
}

int main() {
  return 0;
}
