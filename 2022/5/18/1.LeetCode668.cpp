/*************************************************************************
	> File Name: 1.LeetCode668.cpp
	> Author: 
	> Mail: 
	> Created Time: 2022年05月18日 星期三 08时19分07秒
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

int find_last_lt(int m, int n, int k) {
  int cnt = 0;
  for (int i = 1; i <= m; i++) {
    int l = 1, r = n;
    while (l < r) {
      int mid = (l + r + 1) / 2;
      if (i * mid >= k) r = mid - 1;
      else l = mid;
    }
    cnt += l + (i * l < k ? 0 : -1);
  }
  return cnt;
}

PII find_last_le(int m, int n, int k) {
  int cnt = 0;
  int find = 0;
  for (int i = 1; i <= m; i++) {
    int l = 1, r = n;
    while (l < r) {
      int mid = (l + r + 1) / 2;
      if (i * mid > k) r = mid - 1;
      else l = mid;
    }
    cnt += l + (i * l <= k ? 0 : -1);
    if (i * l == k) find = 1;
  }
  return PII(cnt, find);
}

int findKthNumber(int m, int n, int k) {
  if (m < n) return findKthNumber(n, m, k);
  int l = 1, r = m * n;
  while (l < r) {
    int mid = (l + r + 1) / 2;
    int cnt_1 = find_last_lt(m, n, mid);
    auto [cnt_2, find] = find_last_le(m, n, mid);
    if (cnt_1 >= k) {
      r = mid - 1;
      continue;
    }
    if (cnt_2 < k) {
      l = mid;
      continue;
    }
    if (find) return mid;
    else r = mid - 1;
  }
  return l;
}

int main() {
  return 0;
}
