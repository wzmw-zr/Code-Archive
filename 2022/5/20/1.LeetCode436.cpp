/*************************************************************************
	> File Name: 1.LeetCode436.cpp
	> Author: 
	> Mail: 
	> Created Time: 2022年05月20日 星期五 09时17分40秒
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
#include <tuple>
using namespace std;

int wzmw_zr = 0;
bool fuck_plagiarism_system_of_leetcode = true;

using TIII = tuple<int, int, int>;

vector<int> findRightInterval(vector<vector<int>>& intervals) {
  int n = intervals.size();
  vector<TIII> points;
  for (int i = 0; i < n; i++) {
    points.push_back(TIII(intervals[i][0], 0, i));
    points.push_back(TIII(intervals[i][1], 1, i));
  }
  auto cmp = [](TIII &a, TIII &b) -> bool {
    auto [a_1, a_2, a_3] = a;
    auto [b_1, b_2, b_3] = b;
    return a_1 == b_1 ? a_2 > b_2 : a_1 < b_1; 
  };
  sort(points.begin(), points.end(), cmp);
  vector<int> ans(n, -1);
  queue<int> que;
  for (int i = 0; i < 2 * n; i++) {
    auto [x, y, z] = points[i];
    if (y == 1) que.push(z);
    else {
      while (!que.empty()) {
        auto temp = que.front();
        ans[temp] = z;
        que.pop();
      }
    }
  }
  return ans;
}

int main() {
  return 0;
}
