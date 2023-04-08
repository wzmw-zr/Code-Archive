/*************************************************************************
	> File Name: 1.LeetCode1125.cpp
	> Author: 
	> Mail: 
	> Created Time: 2023年04月08日 星期六 09时42分27秒
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
#include <functional>
using namespace std;

int wzmw_zr = 0;
bool fuck_plagiarism_system_of_leetcode = true;

// TLE
const long inf = 0x3f3f3f3f3f3f3f3f;

vector<int> smallestSufficientTeam(vector<string>& req_skills, vector<vector<string>>& people) {
  int n = req_skills.size(), m = people.size();

  unordered_map<string, int> mp;
  for (int i = 0; i < n; i++)
    mp[req_skills[i]] = i;

  vector<int> states(m, 0);
  for (int i = 0; i < m; i++) {
    for (string &s : people[i])
      states[i] |= 1 << mp[s];
  }

  vector<long> dp1(1 << n, inf), dp2(1 << n, (1L << m) - 1);
  dp1[0] = 0;
  dp2[0] = 0;
  for (int i = 0; i < m; i++) {
    dp1[states[i]] = 1;
    dp2[states[i]] = 1L << i;
  }

  function<long(int)> dfs = [&](int state) -> long {
    if (dp1[state] != inf)
      return dp2[state];
    int mmin = m;
    long ans = (1L << m) - 1;
    for (int i = (state - 1) & state; i > 0; i = (i - 1) & state) {
      long p1 = dfs(i);
      for (int j = (i - 1) & i; j >= 0; j = (j - 1) & i) {
        long p2 = dfs(state - i + j);
        if (__builtin_popcountll(p1 | p2) < mmin) {
          mmin = __builtin_popcountll(p1 | p2);
          ans = p1 | p2;
        }
        if (j == 0)
          break;
      }
    }
    dp1[state] = mmin;
    return dp2[state] = ans;
  };

  long p = dfs((1 << n) - 1);
  vector<int> ans;
  for (int i = 0; i < m; i++) {
    if (p & (1L << i))
      ans.push_back(i);
  }
  return ans;
}

int main() {
  return 0;
}
