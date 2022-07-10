/*************************************************************************
	> File Name: 3.LeetCode6119.cpp
	> Author: 
	> Mail: 
	> Created Time: 2022年07月10日 星期日 15时31分19秒
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

int wzmw_zr = 0;
bool fuck_plagiarism_system_of_leetcode = true;

using PII = pair<int, int>;

struct Union {
  int n;
  vector<int> cnt;
  vector<int> fa;

  Union() = default;
  Union(int n) : n(n), cnt(vector<int>(n, 1)), fa(vector<int>(n)) {
    for (int i = 0; i < n; i++) fa[i] = i;
  }

  int get(int x) {
    return fa[x] = (x == fa[x] ? x : get(fa[x]));
  }

  void merge(int x, int y) {
    int a = get(x);
    int b = get(y);
    if (a == b) return;
    fa[a] = b;
    cnt[b] += cnt[a];
  }
};

int validSubarraySize(vector<int>& nums, int threshold) {
  int n = nums.size();
  int k = 1;
  priority_queue<PII> que;
  Union u(n);
  for (int i = 0; i < n; i++) que.push(PII(nums[i], i));
  while (!que.empty()) {
    auto q = que.top();
    k = (int) ceil(1.0 * threshold / (q.first * 1.0));
    if (k * q.first == threshold) k++;
    int val = threshold / k;
    while (!que.empty() && que.top().first > val) {
      auto [x, ind] = que.top();
      que.pop();
      if (ind > 0 && nums[ind - 1] > val) u.merge(ind - 1, ind);
      if (ind < n - 1 && nums[ind + 1] > val) u.merge(ind, ind + 1);
      int cnt = u.cnt[u.get(ind)];
      if (cnt >= k) return k;
    }
  }
  return -1;
}

int main() {
  return 0;
}
