/*************************************************************************
	> File Name: 2.bishi.cpp
	> Author: 
	> Mail: 
	> Created Time: 2023年08月20日 星期日 19时17分59秒
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


using PDD = pair<double, double>;

int main() {
  int n;
  cin >> n;
  vector<PDD> points;
  for (int i = 0; i < n; i++) {
    double x, y;
    cin >> x >> y;
    points.push_back(PDD(x, y));
  }
  vector<vector<int>> check(10, vector<int>(5000, 0));
  vector<vector<double>> val(10, vector<double>(5000, 0));
  function<double(int, int, int)> dfs = [&](int ind, int state, int start) -> double {
    if (__builtin_popcount(state) == n) {
      auto [x1, y1] = points[ind];
      auto [x2, y2] = points[start];
      return sqrt(pow(x1 - x2, 2) + pow(y1 - y2, 2));
    }
    if (check[ind][state])
      return val[ind][state];
    double ans = 0.0;
    for (int i = 0; i < n; i++) {
      if (state & (1 << i))
        continue;
      auto [x1, y1] = points[ind];
      auto [x2, y2] = points[i];
      ans = max(ans, dfs(i, state | (1 << i), start) + sqrt(pow(x2 - x1, 2) + pow(y2 - y1, 2)));
    }
    check[ind][state] = 1;
    return val[ind][state] = ans;
  };
  double ans = 0.0;
  for (int i = 0; i < n; i++) {
    ans = max(ans, dfs(i, (1 << i), i));
  }
  cout << ans << endl;
  return 0;
}
