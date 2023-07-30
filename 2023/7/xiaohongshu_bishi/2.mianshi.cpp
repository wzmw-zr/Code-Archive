/*************************************************************************
	> File Name: 2.mianshi.cpp
	> Author: 
	> Mail: 
	> Created Time: 2023年07月23日 星期日 19时28分40秒
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


using PII = pair<int, int>;

int main() {
  int n, m, k;
  cin >> n >> m >> k;
  vector<PII> intervals;
  for (int i = 0; i < m; i++) {
    int l, r;
    cin >> l >> r;
    intervals.push_back(PII(l, r - 1));
  }
  sort(intervals.begin(), intervals.end());
  vector<int> pre(m + 1, 0);
  for (int i = 0; i < m; i++)
    pre[i + 1] = pre[i] + intervals[i].second - intervals[i].first + 1;
  int ans = 0;
  for (int i = 0; i < m; i++) {
    int left = intervals[i].second - k + 1;
    int l = 0, r = i;
    while (l < r) {
      int mid = (l + r) / 2;
      if (intervals[mid].second >= left)
        r = mid;
      else
        l = mid + 1;
    }
    ans = max(ans, pre[i + 1] - pre[l + 1] + intervals[l].second - max(intervals[l].first, left) + 1);
  }
  cout << ans << endl;
  return 0;
}
