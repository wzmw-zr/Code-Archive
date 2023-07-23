/*************************************************************************
	> File Name: 5.LeetCode6955.cpp
	> Author: 
	> Mail: 
	> Created Time: 2023年07月23日 星期日 10时59分44秒
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

using PII = pair<int, int>;

int maxIncreasingGroups(vector<int>& usageLimits) {
  int n = usageLimits.size();
  function<bool(PII, PII)> cmp = [&](PII x, PII y) {
    return x.second == y.second ? x.first < y.first : x.second < y.second;
  };
  priority_queue<PII, vector<PII>, decltype(cmp)> que(cmp);
  for (int i = 0; i < n; i++)
    que.push(PII(i, usageLimits[i]));
  int cnt = 1;
  while (1) {
    vector<PII> tmp;
    int i = 0;
    while (i < cnt && !que.empty()) {
      auto t = que.top();
      que.pop();
      if (--t.second)
        tmp.push_back(t);
      i++;
    }
    if (i == cnt)
      cnt++;
    else
      return cnt - 1;
    for (auto && t : tmp)
      que.push(t);
  }
  return -1;
}

int main() {
  return 0;
}
