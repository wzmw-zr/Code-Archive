/*************************************************************************
	> File Name: 1.LeetCode2437.cpp
	> Author: 
	> Mail: 
	> Created Time: 2023年05月09日 星期二 09时29分40秒
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

int countTime(string time) {
  int ans = 0;
  function<void(int)> dfs = [&](int ind) {
    if (!time[ind]) {
      int hour = stoi(time.substr(0, 2)), miniute = stoi(time.substr(3));
      if (hour >= 0 && hour <= 23 && miniute >= 0 && miniute <= 59)
        ans++;
      return;
    }
    if (time[ind] != '?') {
      dfs(ind + 1);
      return;
    }
    for (char c = '0'; c <= '9'; c++) {
      time[ind] = c;
      dfs(ind + 1);
    }
    time[ind] = '?';
    return;
  };
  dfs(0);
  return ans;
}

int main() {
  return 0;
}
