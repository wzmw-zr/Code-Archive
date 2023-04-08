/*************************************************************************
	> File Name: 2.LeetCode1125.cpp
	> Author: 
	> Mail: 
	> Created Time: 2023年04月08日 星期六 14时59分06秒
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

vector<int> smallestSufficientTeam(vector<string>& req_skills, vector<vector<string>>& people) {
  int n = req_skills.size(), m = people.size();
  unordered_map<string, int> mp;
  for (int i = 0; i < n; i++)
    mp[req_skills[i]] = i;
  vector<int> states(m, 0);
  for (int i = 0; i < m; i++) {
    for (int j = 0; j < people[i].size(); j++)
      states[i] |= (1 << mp[people[i][j]]);
  }
  vector<int> dp(1 << n, 0x3f3f3f3f);
  vector<int> pre_state(1 << n, 0);
  vector<int> pre_people(1 << n, 0);

  dp[0] = 0;
  for (int j = 0; j < m; j++) {
    for (int i = 0; i < (1 << n); i++) {
      if ((i & states[j]) == states[j])
        continue;
      int next = i | states[j];
      if (dp[next] > dp[i] + 1) {
        dp[next] = dp[i] + 1;
        pre_state[next] = i;
        pre_people[next] = j;
      }
    }
  }
  vector<int> ans;
  int state = (1 << n) - 1;
  while (state) {
    ans.push_back(pre_people[state]);
    state = pre_state[state];
  }
  return ans;
}

int main() {
  return 0;
}
