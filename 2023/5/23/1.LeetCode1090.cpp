/*************************************************************************
	> File Name: 1.LeetCode1090.cpp
	> Author: 
	> Mail: 
	> Created Time: 2023年05月23日 星期二 16时43分43秒
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

int largestValsFromLabels(vector<int>& values, vector<int>& labels, int numWanted, int useLimit) {
  function<int(PII &, PII &)> cmp = [](PII &a, PII &b) -> int {
    return a.second < b.second;
  };
  priority_queue<PII, vector<PII>, decltype(cmp)> que(cmp);
  int n = values.size();
  for (int i = 0; i < n; i++)
    que.push(PII(labels[i], values[i]));
  unordered_map<int, int> cnts;
  int ans = 0;
  while (!que.empty() && numWanted) {
    auto [l, v] = que.top();
    que.pop();
    if (cnts[l] == useLimit)
      continue;
    cnts[l]++;
    ans += v;
    numWanted--;
  }
  return ans;
}

int main() {
  return 0;
}
