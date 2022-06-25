/*************************************************************************
	> File Name: 1.LeetCode2543.cpp
	> Author: 
	> Mail: 
	> Created Time: 2022年06月25日 星期六 09时04分24秒
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

int minCost(vector<vector<int>>& costs) {
  int n = costs.size();
  for (int i = 1; i < n; i++) {
    costs[i][0] += min(costs[i - 1][1], costs[i - 1][2]);
    costs[i][1] += min(costs[i - 1][0], costs[i - 1][2]);
    costs[i][2] += min(costs[i - 1][0], costs[i - 1][1]);
  }
  return min({costs[n - 1][0], costs[n - 1][1], costs[n - 1][2]});
}

int main() {
  return 0;
}
