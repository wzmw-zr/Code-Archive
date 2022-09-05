/*************************************************************************
	> File Name: 2.LeetCode6168.cpp
	> Author: 
	> Mail: 
	> Created Time: 2022年09月05日 星期一 10时20分33秒
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

long MOD = 1e9 + 7;

int numberOfWays(int startPos, int endPos, int k) {
  map<PII, long> mp;
  function<long(int, int)> dfs = [&](int s, int k) -> long {
    if (abs(s - endPos) > k) {
      return 0;
    }
    if (abs(s - endPos) == k) {
      return 1;
    }
    PII state(s, k);
    if (mp.count(state)) {
      return mp[state];
    }
    long ans = 0;
    ans = (ans + dfs(s + 1, k - 1)) % MOD;
    ans = (ans + dfs(s - 1, k - 1)) % MOD;
    return mp[state] = ans;
  };
  return dfs(startPos, k);
}

int main() {
  int startPos, endPos, k;
  cin >> startPos >> endPos >> k;
  cout << numberOfWays(startPos, endPos, k) << endl;
  return 0;
}
