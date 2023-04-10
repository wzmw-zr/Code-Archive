/*************************************************************************
	> File Name: 2.LeetCode2612.cpp
	> Author: 
	> Mail: 
	> Created Time: 2023年04月10日 星期一 14时41分26秒
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

vector<int> minReverseOperations(int n, int p, vector<int>& banned, int k) {
  set<int> st[2];
  for (int i = 0; i < n; i++) 
    st[i & 1].insert(i);
  for (int x : banned)
    st[x & 1].erase(x);
  vector<int> ans(n, -1);
  ans[p] = 0;
  queue<int> que;
  que.push(p);
  st[p & 1].erase(p);

  while (!que.empty()) {
    int ind = que.front();
    que.pop();
    int x = (ind - k + 1) & 1;

    int left = max(k - ind - 1, ind - k + 1);
    int right = min(k + ind - 1, 2 * n - 1 - ind - k);

    auto iter = st[x].lower_bound(left);

    while (iter != st[x].end() && *iter <= right) {
      que.push(*iter);
      ans[*iter] = ans[ind] + 1;
      iter = st[x].erase(iter);
    }
  }

  return ans;
}

int main() {
  return 0;
}
