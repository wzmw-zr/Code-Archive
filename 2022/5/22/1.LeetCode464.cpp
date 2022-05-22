/*************************************************************************
	> File Name: 1.LeetCode464.cpp
	> Author: 
	> Mail: 
	> Created Time: 2022年05月22日 星期日 08时45分02秒
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

bool canIWin(int maxChoosableInteger, int desiredTotal) {
  if (maxChoosableInteger * (maxChoosableInteger + 1) / 2 < desiredTotal) return false;
  int origin_rest = (1 << maxChoosableInteger) - 1;
  map<PII, bool> mp;
  function<bool(int, int)> dfs = [&](int rest, int sum) -> bool {
    PII p(rest, sum);
    if (mp.count(p)) return mp[p];
    if (rest == 0 && sum < desiredTotal) return mp[p] = false;
    bool ans = false;
    for (int i = 0; i < maxChoosableInteger && !ans; i++) {
      if (!(rest & (1 << i))) continue;
      if (sum + i + 1 >= desiredTotal) ans = true;
      else ans |= !dfs(rest - (1 << i), sum + i + 1);
    }
    return mp[p] = ans;
  };
  return dfs(origin_rest, 0);
}

int main() {
  return 0;
}
