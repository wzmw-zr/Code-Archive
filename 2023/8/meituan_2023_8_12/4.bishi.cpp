/*************************************************************************
	> File Name: 4.bishi.cpp
	> Author: 
	> Mail: 
	> Created Time: 2023年08月12日 星期六 10时19分10秒
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

int dir[4][2] = {1, 0, -1, 0, 0, 1, 0, -1};

int calculate(vector<string> &mat) {
  int n = mat.size(), m = mat[0].size();
  vector<vector<int>> check(n, vector<int>(m, 0));
  function<void(int, int, char)> dfs = [&](int x, int y, char c) {
    for (int i = 0; i < 4; i++) {
      int x_t = x + dir[i][0];
      int y_t = y + dir[i][1];
      if (x_t < 0 || x_t >= n || y_t < 0 || y_t >= m || check[x_t][y_t] || mat[x_t][y_t] != c)
        continue;
      check[x_t][y_t] = 1;
      dfs(x_t, y_t, c);
    }
  };
  int ans = 0;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      if (check[i][j])
        continue;
      ans++;
      check[i][j] = 1;
      dfs(i, j, mat[i][j]);
    }
  }
  return ans;
}

int main() {
  int n;
  cin >> n;
  string s;
  cin >> s;
  int ans = INT32_MAX;
  for (int i = 1; i <= n; i++) {
    if (n % i)
      continue;
    vector<string> mat;
    int line = n / i;
    for (int j = 0; j < i; j++)
      mat.push_back(s.substr(j * line, line));
    ans = min(ans, calculate(mat));
  }
  cout << ans << endl;
  return 0;
}
