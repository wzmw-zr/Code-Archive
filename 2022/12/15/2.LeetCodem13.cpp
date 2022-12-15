/*************************************************************************
	> File Name: 2.LeetCodem13.cpp
	> Author: 
	> Mail: 
	> Created Time: 2022年12月15日 星期四 16时53分52秒
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

int dir[4][2] = {1, 0, -1, 0, 0, 1, 0, -1};

int calc(int x, int y) {
  int ans = 0;
  while (x) {
    ans += x % 10;
    x /= 10;
  }
  while (y) {
    ans += y % 10;
    y /= 10;
  }
  return ans;
}

struct UnionSet {
  int n;
  vector<int> vals;
  vector<int> fa;

  UnionSet() = default;
  UnionSet(int n) : n(n), vals(vector<int>(n, 1)), fa(vector<int>(n)) {
    for (int i = 0; i < n; i++)
      fa[i] = i;
  }

  int get(int x) {
    return fa[x] = (x == fa[x] ? x : get(fa[x]));
  }

  void merge(int x, int y) {
    int a = get(x);
    int b = get(y);
    if (a == b)
      return ;
    fa[a] = b;
    vals[b] += vals[a];
  }
};

int movingCount(int m, int n, int k) {
  UnionSet u(m * n);
  for (int i = 0; i < m; i++) {
    for (int j = 0; j < n; j++) {
      int x = i, y = j;
      int val = calc(x, y);
      if (val <= k) {
        for (int p = 0; p < 4; p++) {
          int x_t = x + dir[p][0];
          int y_t = y + dir[p][1];
          if (x_t < 0 || x_t >= m || y_t < 0 || y_t >= n)
            continue;
          if (calc(x_t, y_t) <= k) 
            u.merge(x * n + y, x_t * n + y_t);
        }
      }
    }
  }
  return u.vals[u.get(0)];
}

int main() {
  return 0;
}
