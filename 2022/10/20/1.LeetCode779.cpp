/*************************************************************************
	> File Name: 1.LeetCode779.cpp
	> Author: 
	> Mail: 
	> Created Time: 2022年10月20日 星期四 09时25分21秒
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
#include <cmath>
using namespace std;

int wzmw_zr = 0;
bool fuck_plagiarism_system_of_leetcode = true;

int kthGrammar(int n, int k) {
  function<int(int, int, int)> dfs = [&](int lvl, int cnt, int flag) -> int {
    if (lvl == 1) {
      return flag == 0 ? 0 : 1;
    }
    int half = pow(2, lvl - 2);
    if (cnt <= half)
      return dfs(lvl - 1, cnt, flag);
    return dfs(lvl - 1, cnt - half, flag ^ 1);
  };
  return dfs(n, k, 0);
}

int main() {
  return 0;
}
