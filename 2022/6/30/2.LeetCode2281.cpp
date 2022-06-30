/*************************************************************************
	> File Name: 2.LeetCode2281.cpp
	> Author: 
	> Mail: 
	> Created Time: 2022年06月30日 星期四 11时49分18秒
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

long MOD = 1e9 + 7;

int totalStrength(vector<int>& strength) {
  int n = strength.size();
  vector<long> pre(n + 1, 0);
  vector<long> ppre(n + 2, 0);
  vector<int> left_lt(n);
  vector<int> right_lt(n);

  for (int i = 1; i <= n; i++) pre[i] = (pre[i - 1] + strength[i - 1]) % MOD;
  for (int i = 1; i <= n + 1; i++) ppre[i] = (ppre[i - 1] + pre[i - 1]) % MOD;

  stack<int> st;
  for (int i = 0; i < n; i++) {
    left_lt[i] = i;
    while (!st.empty() && strength[st.top()] >= strength[i]) st.pop();
    if (st.empty()) {
      left_lt[i] = 0;
    } else {
      left_lt[i] = st.top() + 1;
    }
    st.push(i);
  }
  while (!st.empty()) st.pop();
  for (int i = n - 1; i >= 0; i--) {
    right_lt[i] = i;
    while (!st.empty() && strength[st.top()] > strength[i]) st.pop();
    if (st.empty()) {
      right_lt[i] = n - 1;
    } else {
      right_lt[i] = st.top() - 1;
    }
    st.push(i);
  }

  long ans = 0;

  for (int i = 0; i < n; i++) {
    int l = left_lt[i];
    int r = right_lt[i];
    long cnt = ((ppre[r + 2] - ppre[i + 1]) * (i - l + 1) - (ppre[i + 1] - ppre[l]) * (r - i + 1)) % MOD;
    cnt = cnt * strength[i] % MOD;
    ans = (ans + cnt) % MOD;
  }
  return (ans + MOD) % MOD;
}

int main() {
  return 0;
}
