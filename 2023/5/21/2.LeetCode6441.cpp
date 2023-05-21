/*************************************************************************
	> File Name: 2.LeetCode6441.cpp
	> Author: 
	> Mail: 
	> Created Time: 2023年05月21日 星期日 10时37分50秒
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


int check(int x) {
  string s = to_string(x * x);
  int sum = 0;
  function<bool(int)> dfs = [&](int ind) -> bool {
    if (ind == s.size())
      return sum == x;
    if (sum > x)
      return false;
    bool ans = false;
    for (int l = 1; l <= (s.size() - ind) && !ans; l++) {
      int num = stoi(s.substr(ind, l));
      sum += num;
      ans |= dfs(ind + l);
      sum -= num;
    }
    return ans;
  };
  return dfs(0);
}

int punishmentNumber(int n) {
  int ans = 0;
  for (int i = 1; i <= n; i++)
    ans += check(i) ? i * i : 0;
  return ans;
}

int main() {
  return 0;
}
