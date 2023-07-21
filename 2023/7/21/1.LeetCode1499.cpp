/*************************************************************************
	> File Name: 1.LeetCode1499.cpp
	> Author: 
	> Mail: 
	> Created Time: 2023年07月21日 星期五 09时23分37秒
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
#include <cstdint>
using namespace std;

int findMaxValueOfEquation(vector<vector<int>>& points, int k) {
  int n = points.size();
  function<bool(int, int)> cmp = [&](int x, int y) -> bool {
    return (points[x][1] - points[x][0]) < (points[y][1] - points[y][0]);
  };
  priority_queue<int, vector<int>, decltype(cmp)> que(cmp);
  que.push(0);
  int ans = INT32_MIN;
  for (int i = 1; i < n; i++) {
    while (!que.empty() && points[i][0] - points[que.top()][0] > k)
      que.pop();
    if (!que.empty())
      ans = max(ans, points[i][0] + points[i][1] + points[que.top()][1] - points[que.top()][0]);
    que.push(i);
  }
  return ans;
}

int main() {
  return 0;
}
