/*************************************************************************
	> File Name: 1.LeetCode593.cpp
	> Author: 
	> Mail: 
	> Created Time: 2022年07月29日 星期五 09时30分29秒
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

void dfs(vector<vector<int>> &orders, vector<int> &order, vector<int> &check, int ind) {
  if (ind == 4) {
    orders.push_back(order);
    return ;
  }
  for (int i = 0; i < 4; i++) {
    if (check[i]) continue;
    check[i] = 1;
    order.push_back(i);
    dfs(orders, order, check, ind + 1);
    order.pop_back();
    check[i] = 0;
  }
}

bool validSquare(vector<int>& p1, vector<int>& p2, vector<int>& p3, vector<int>& p4) {
  vector<vector<int>> orders;
  vector<int> order;
  vector<int> check(4, 0);
  dfs(orders, order, check, 0);
  vector<vector<int>> points({p1, p2, p3, p4});
  for (auto && pos : orders) {
    int flag = 0;
    for (int i = 0; i < 4; i++) {
      vector<int> x = points[pos[i]];
      vector<int> y = points[pos[(i + 1) % 4]];
      vector<int> z = points[pos[(i + 2) % 4]];
      vector<int> v1({y[0] - x[0], y[1] - x[1]});
      vector<int> v2({z[0] - y[0], z[1] - y[1]});
      if ((v1[0] * v2[0] + v1[1] * v2[1] == 0) 
          && ((v1[0] * v1[0] + v1[1] * v1[1]) == (v2[0] * v2[0] + v2[1] * v2[1]))
          && ((v1[0] * v1[0] + v1[1] * v1[1]) > 0))
      continue;
      flag = 1;
      break;
    }
    if (flag) continue;
    return true;
  }
  return false;
}

int main() {
  return 0;
}
