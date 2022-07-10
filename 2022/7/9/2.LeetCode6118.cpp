/*************************************************************************
	> File Name: 2.LeetCode6118.cpp
	> Author: 
	> Mail: 
	> Created Time: 2022年07月09日 星期六 22时50分14秒
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

using PLL = pair<long, long>;

long long minSumSquareDiff(vector<int>& nums1, vector<int>& nums2, int k1, int k2) {
  int n = nums1.size();
  long total = k1 + k2;
  vector<long> dis(n);
  for (int i = 0; i < n; i++) dis[i] = abs(nums1[i] - nums2[i]);
  auto cmp = [](PLL &x, PLL &y) {
    return x.first < y.first;
  };
  priority_queue<PLL, vector<PLL>, decltype(cmp)> que(cmp);
  unordered_map<long, long> mp;
  for (long x : dis) mp[x]++;
  for (auto && [x, cnt] : mp) que.push(PLL(x, cnt));
  while (total && !que.empty()) {
    auto p1 = que.top();
    que.pop();
    if (que.empty()) {
      auto [x, cnt] = p1;
      long group = total / cnt;
      long rest = total % cnt;
      total = max(static_cast<long>(0), total - x * cnt);
      if (group < x) {
        x -= group;
        que.push(PLL(x, cnt - rest));
        if (rest && x > 1) que.push(PLL(x - 1, rest));
      }
    } else {
      auto p2 = que.top();
      que.pop();
      auto [x1, cnt1] = p1;
      auto [x2, cnt2] = p2;
      if ((x1 - x2) * cnt1 <= total) {
        total -= (x1 - x2) * cnt1;
        que.push(PLL(x2, cnt1 + cnt2));
      } else {
        long group = total / cnt1;
        long rest = total % cnt1;
        x1 -= group;
        que.push(PLL(x1, cnt1 - rest));
        if (rest && x1 > 1) {
          if (x1 - 1 == x2) {
            que.push(PLL(x2, cnt2 + rest));
          } else {
            que.push(PLL(x1 - 1, rest));
            que.push(p2);
          }
        }
        total = 0;
      }
    }
  }
  long ans = 0;
  while (!que.empty()) {
    auto [x, cnt] = que.top();
    que.pop();
    ans = ans + x * x * cnt;
  }
  return ans;
}

int main() {
  return 0;
}
