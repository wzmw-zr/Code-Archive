/*************************************************************************
	> File Name: 2.LeetCode1039.cpp
	> Author: 
	> Mail: 
	> Created Time: 2023年04月02日 星期日 10时21分19秒
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

using PII = pair<int, int>;

int minScoreTriangulation(vector<int>& values) {
  int n = values.size();
  map<PII, int> mp;
  function<int(int, int)> dfs = [&](int x, int y) -> int {
    if (x + 2 > y)
      return 0;
    if (x + 2 == y)
      return values[x] * values[x + 1] * values[x + 2];
    PII state(x, y);
    if (mp.count(state))
      return mp[state];
    int ans = INT32_MAX;
    for (int k = x + 1; k < y; k++)
      ans = min(ans, values[x] * values[k] * values[y] + dfs(x, k) + dfs(k, y));
    return mp[state] = ans;
  };
  return dfs(0, n - 1);
}

int main() {
  return 0;
}
