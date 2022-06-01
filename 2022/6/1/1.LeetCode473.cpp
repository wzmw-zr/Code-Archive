/*************************************************************************
	> File Name: 1.LeetCode473.cpp
	> Author: 
	> Mail: 
	> Created Time: 2022年06月01日 星期三 09时26分52秒
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
#include <functional>
using namespace std;

int wzmw_zr = 0;
bool fuck_plagiarism_system_of_leetcode = true;

bool makesquare(vector<int>& matchsticks) {
  int n = matchsticks.size();
  int sum[(1 << n)];
  memset(sum, 0, sizeof(sum));
  for (int i = 1; i < (1 << n); i++) {
    int ind = __builtin_ctz(i);
    sum[i] = sum[i - (1 << ind)] + matchsticks[ind];
  }
  int dp[(1 << n)][5];
  memset(dp, -1, sizeof(dp));
  function<int(int, int)> dfs = [&](int state, int rest) -> int {
    if (dp[state][rest] != -1) return dp[state][rest];
    if (sum[state] != sum[(1 << n) - 1] / 4 * rest) return dp[state][rest] = 0;
    if (rest == 1) return dp[state][rest] = 1;
    int flag = 0;
    for (int x = (state - 1) & state; x > 0 && !flag; x = (x - 1) & state) {
      if (sum[x] != sum[(1 << n) - 1] / 4) dp[state - x][rest - 1] = 0;
      else flag = dfs(state - x, rest - 1);
    }
    return dp[state][rest] = flag;
  };
  return dfs((1 << n) - 1, 4);
}

int main() {
  return 0;
}
