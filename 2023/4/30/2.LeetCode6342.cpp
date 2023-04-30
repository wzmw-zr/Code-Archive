/*************************************************************************
	> File Name: 2.LeetCode6342.cpp
	> Author: 
	> Mail: 
	> Created Time: 2023年04月30日 星期日 10时41分59秒
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

using PII = pair<int, int>;

int firstCompleteIndex(vector<int>& arr, vector<vector<int>>& mat) {
  int m = mat.size(), n = mat[0].size();
  vector<PII> mp(m * n + 1, PII(0, 0));
  for (int i = 0; i < m; i++) {
    for (int j = 0; j < n; j++) {
      mp[mat[i][j]] = PII(i, j);
    }
  }
  vector<int> rcnts(m, 0);
  vector<int> ccnts(n, 0);
  for (int i = 0; i < m * n; i++) {
    auto [x, y] = mp[arr[i]];
    rcnts[x]++, ccnts[y]++;
    if (rcnts[x] == n || ccnts[y] == m)
      return i;
  }
  return -1;
}

int main() {
  return 0;
}
