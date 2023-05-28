/*************************************************************************
	> File Name: 3.LeetCode6456.cpp
	> Author: 
	> Mail: 
	> Created Time: 2023年05月28日 星期日 11时25分56秒
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

// WA
using PII = pair<int, int>;

int maxIncreasingCells(vector<vector<int>>& mat) {
  int m = mat.size(), n = mat[0].size();
  vector<PII> pos;
  for (int i = 0; i < m; i++) {
    for (int j = 0; j < n; j++)
      pos.push_back(PII(i, j));
  }
  sort(pos.begin(), pos.end(), [&](PII &a, PII &b){
    return mat[a.first][a.second] < mat[b.first][b.second];
  });
  vector<int> old_rows(m, 0), old_cols(n, 0);
  vector<int> rows(m, 0), cols(n, 0);
  vector<int> row_val(m, INT32_MIN), col_val(n, INT32_MIN);
  int ans = 0;
  for (auto && [x, y] : pos) {
    int cnt = max(mat[x][y] > row_val[x] ? rows[x] + 1 : old_rows[x] + 1, mat[x][y] > col_val[y] ? cols[y] + 1 : old_cols[y] + 1);
    if (mat[x][y] > row_val[x])
      old_rows[x] = rows[x];
    if (mat[x][y] > col_val[y])
      old_cols[y] = cols[y];
    rows[x] = cols[y] = cnt;
    row_val[x] = col_val[y] = mat[x][y];
    ans = max(ans, cnt);
  }
  return ans;
}

int main() {
  return 0;
}
