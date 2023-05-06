/*************************************************************************
	> File Name: 3.mianshi.cpp
	> Author: 
	> Mail: 
	> Created Time: 2023年05月06日 星期六 20时48分23秒
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
#include <cstring>
#include <cstdlib>
#include <tuple>
using namespace std;

using PII = pair<int, int>;
using TIII = tuple<int, int, int>;
int dir[5][2] = {1, 0, -1, 0, 0, 1, 0, -1, 0, 0};

int minTime(vector<vector<string>> &states, vector<int> target, vector<int> start) {
  int n = states.size();
  int mmin_time[n][n][3];
  memset(mmin_time, 0x3f, sizeof(mmin_time));
  queue<TIII> que;
  que.push(TIII(start[0], start[1], 0));

  mmin_time[start[0]][start[1]][0] = 0;

  while (!que.empty()) {
    int len = que.size();
    for (int i = 0; i < len; i++) {
      auto [x, y, t] = que.front();
      que.pop();
      if (x == target[0] && y == target[1])
        return t;
      for (int j = 0; j < 5; j++) {
        int x_t = x + dir[j][0];
        int y_t = y + dir[j][1];
        if (x_t < 0 || x_t >= n || y_t < 0 || y_t >= n)
          continue;
        if (states[x_t][y_t][(t + 1) % 3] == '1')
          continue;
        if (mmin_time[x_t][y_t][(t + 1) % 3] != 0x3f3f3f3f)
          continue;
        mmin_time[x_t][y_t][(t + 1) % 3] = t + 1;
        que.push(TIII(x_t, y_t, t + 1));
      }
    }
  }
  return -1;
}

int main() {
  int n, k;
  cin >> n >> k;
  vector<PII> monsters;
  int row, col;
  for (int i = 0; i < k; i++) {
    cin >> row >> col;
    monsters.push_back(PII(row, col));
  }
  int row_1, col_1, row_2, col_2;
  cin >> row_1 >> col_1 >> row_2 >> col_2;

  vector<vector<string>> states(n, vector<string>(n));
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++)
      cin >> states[i][j];
  }
  for (auto && [x, y] : monsters)
    states[x][y] = "111";

  cout << minTime(states, {row_1, col_1}, {row_2, col_2}) << endl;
  return 0;
}
