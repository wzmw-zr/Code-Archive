/*************************************************************************
	> File Name: 1.LeetCode2462.cpp
	> Author: 
	> Mail: 
	> Created Time: 2022年11月10日 星期四 09时37分23秒
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
using namespace std;

int wzmw_zr = 0;
bool fuck_plagiarism_system_of_leetcode = true;

using PII = pair<int, int>;
long long totalCost(vector<int>& costs, int k, int candidates) {
  int n = costs.size();
  int x = 0, y = n - 1;
  priority_queue<PII, vector<PII>, greater<PII>> que;
  while (x < n && x < candidates) {
    que.push(PII(costs[x], x));
    x++;
  }
  while (y > x && (y >= n - candidates)) {
    que.push(PII(costs[y], y));
    y--;
  }
  long long ans = 0;
  while (k) {
    auto [cost, ind] = que.top();
    que.pop();
    ans += cost;
    k--;
    if (x > y)
      continue;
    if (ind <= x) {
      que.push(PII(costs[x], x));
      x++;
    } else if (ind >= y) {
      que.push(PII(costs[y], y));
      y--;
    }
  }
  return ans;
}

int main() {
  return 0;
}
