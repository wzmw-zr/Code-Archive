/*************************************************************************
	> File Name: 2.LeetCode2376.cpp
	> Author: 
	> Mail: 
	> Created Time: 2022年08月31日 星期三 15时01分40秒
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

int countSpecialNumbers(int n) {
  int dp[10][(1 << 10)][2];
  int check[10][(1 << 10)][2];
  memset(dp, 0, sizeof(dp));
  memset(check, 0, sizeof(check));
  vector<int> digits;
  int t = n;
  do {
    digits.push_back(t % 10);
    t /= 10;
  } while (t);

  reverse(digits.begin(), digits.end());
  int m = digits.size();
  function<int(int, int, int)> dfs = [&](int ind, int mask, int is_limit) -> int {
    if (ind == m)
      return mask == 0 ? 0 : 1;
    if (check[ind][mask][is_limit])
      return dp[ind][mask][is_limit];
    int up = is_limit ? digits[ind] : 9;
    int cnt = 0;
    for (int i = 0; i <= up; i++) {
      if (mask & (1 << i)) 
        continue;
      if (i == 0 && __builtin_popcount(mask) == 0)
        cnt += dfs(ind + 1, mask, is_limit ? (i == up ? 1 : 0) : 0);
      else
        cnt += dfs(ind + 1, mask | (1 << i), is_limit ? (i == up ? 1 : 0) : 0);
    }
    dp[ind][mask][is_limit] = cnt;
    check[ind][mask][is_limit] = 1;
    return cnt;
  };
  return dfs(0, 0, 1);
}

int main() {
  int n;
  cin >> n;
  cout << countSpecialNumbers(n) << endl;
  return 0;
}
