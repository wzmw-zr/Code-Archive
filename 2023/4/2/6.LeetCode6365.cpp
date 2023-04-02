/*************************************************************************
	> File Name: 6.LeetCode6365.cpp
	> Author: 
	> Mail: 
	> Created Time: 2023年04月02日 星期日 11时00分45秒
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

// TLE
vector<int> minReverseOperations(int n, int p, vector<int>& banned, int k) {
  vector<int> min_dis(n, -1);
  min_dis[p] = 0;
  queue<PII> que;
  que.push(PII(p, 0));
  vector<int> is_banned(n, 0);
  for (int x : banned)
    is_banned[x] = 1;
  while (!que.empty()) {
    int len = que.size();
    for (int i = 0; i < len; i++) {
      auto [ind, step] = que.front();
      que.pop();
      int x = max(0, ind - k + 1);
      int y = min(ind, n - k);
      // cout << "ind = " << ind << ", step = " << step << ", x = " << x << ", y = " << y << endl;
      for (int j = x; j <= y; j++) {
        int pos = j + k - (ind - j + 1);
        if (is_banned[pos] || min_dis[pos] != -1)
          continue;
        que.push(PII(pos, step + 1));
        min_dis[pos] = step + 1;
      }
    }
  }
  return min_dis;
}

int main() {
  vector<int> banned;
  auto ans = minReverseOperations(5, 0, banned, 2);
  for (int x : ans)
    cout << x << " ";
  cout << endl;
  return 0;
}
