/*************************************************************************
	> File Name: 2.bishi.cpp
	> Author: 
	> Mail: 
	> Created Time: 2023年08月20日 星期日 14时14分21秒
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
#include <cmath>
using namespace std;

int dir[8][2] = {1, 0, -1, 0, 0, 1, 0, -1, 1, 1, 1, -1, -1, 1, -1, -1};

double calculate(int state, int n, int m, int c, double d) {
  double ans = 0;
  for (int x = 0; x < n; x++) {
    for (int y = 0; y < m; y++) {
      int ind = x * m + y;
      if (state & (1 << ind)) {
        int cnt = 0;
        for (int i = 0; i < 8; i++) {
          int x_t = x + dir[i][0];
          int y_t = y + dir[i][1];
          if (x_t < 0 || x_t >= n || y_t < 0 || y_t >= m)
            continue;
          int ind_2 = x_t * m + y_t;
          if (!(state & (1 << ind_2)))
            cnt++;
        }
        ans += 1.0 * c * pow(d, cnt);
      }
    }
  }
  return ans;
}

int main() {
  int n, m, c;
  double d;
  cin >> n >> m >> c >> d;
  int state = (1 << (n * m)) - 1;
  int tmp = (1 << (n * m)) - 1;
  vector<double> sum(n * m + 1, 0);
  vector<int> cnts(n * m + 1, 0);
  while (state) {
    double val = calculate(state, n, m, c, d);
    int ind = n * m - __builtin_popcount(state);
    sum[ind] += val;
    cnts[ind]++;
    state = tmp & (state - 1);
  }
  double mmax = 0;
  for (int i = 0; i < (n * m); i++) {
    sum[i] /= cnts[i];
    mmax = max(mmax, sum[i]);
  }
  for (int i = 0; i < (n * m); i++) {
    if (mmax == sum[i]) {
      printf("%d %d %.1f\n", i, n * m - i, mmax);
      return 0;
    }
  }
  return 0;
}
