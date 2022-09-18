/*************************************************************************
	> File Name: 1.LeetCode827.cpp
	> Author: 
	> Mail: 
	> Created Time: 2022年09月18日 星期日 09时04分12秒
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

struct UnionSet {
  vector<int> cnt;
  vector<int> fa;

  UnionSet() = default;
  UnionSet(vector<vector<int>> &grid) : cnt(vector<int>(grid.size() * grid.size(), 0)), fa(vector<int>(grid.size() * grid.size(), 0)) {
    int n = grid.size();
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++) {
        cnt[i * n + j] = grid[i][j];
        fa[i * n + j] = i * n + j;
      }
    }
  }

  int get(int x) {
    return fa[x] = (x == fa[x] ? x : get(fa[x]));
  }

  void merge(int x, int y) {
    int a = get(x);
    int b = get(y);
    if (a == b)
      return ;
    cnt[a] += cnt[b];
    fa[b] = a;
  }
};

int largestIsland(vector<vector<int>>& grid) {
  int n = grid.size();
  UnionSet u(grid);
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      if (!grid[i][j])
        continue;
      for (int k = 0; k < 4; k++) {
        int x = i + dir[k][0];
        int y = j + dir[k][1];
        if (x < 0 || x >= n || y < 0 || y >= n)
          continue;
        if (grid[x][y])
          u.merge(i * n + j, x * n + y);
      }
    }
  }
  int ans = 0;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      if (grid[i][j]) {
        ans = max(ans, u.cnt[u.get(i * n + j)]);
        continue;;
      }
      int cnt = 1;
      unordered_set<int> neigbor;
      for (int k = 0; k < 4; k++) {
        int x = i + dir[k][0];
        int y = j + dir[k][1];
        if (x < 0 || x >= n || y < 0 || y >= n)
          continue;
        if (grid[x][y]) 
          neigbor.insert(u.get(x * n + y));
      }
      for (int x : neigbor)
        cnt += u.cnt[x];
      ans = max(ans, cnt);
    }
  }
  return ans;
}

int main() {
  return 0;
}
