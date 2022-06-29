/*************************************************************************
	> File Name: 2.LeetCode2281.cpp
	> Author: 
	> Mail: 
	> Created Time: 2022年06月29日 星期三 18时46分50秒
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

// WA
long MOD = 1e9 + 7;

int totalStrength(vector<int>& strength) {
  int n = strength.size();
  vector<long> pre(n + 1, 0);
  vector<long> ppre(n + 2, 0);
  for (int i = 0; i < n; i++) pre[i + 1] = (pre[i] + strength[i]) % MOD;
  for (int i = 1; i <= n; i++) ppre[i + 1] = (ppre[i] + pre[i]) % MOD;

  vector<int> left_lt(n, 0);
  vector<int> right_lt(n, n - 1);
  stack<int> st;
  for (int i = 0; i < n; i++) {
    while (!st.empty() && strength[st.top()] >= strength[i]) {
      left_lt[i] = left_lt[st.top()];
      st.pop();
    }
    if (st.empty()) left_lt[i] = 0;
    else left_lt[i] = st.top() + 1;
    st.push(i);
  }
  while (!st.empty()) st.pop();

  for (int i = n - 1; i >= 0; i--) {
    while (!st.empty() && strength[st.top()] >= strength[i]) {
      right_lt[i] = right_lt[st.top()];
      st.pop();
    }
    if (st.empty()) right_lt[i] = n - 1;
    else right_lt[i] = st.top() - 1;
    st.push(i);
  }
  while (!st.empty()) st.pop();

  long ans = 0;
  for (int i = 0; i < n; i++) {
    int l = left_lt[i];
    int r = right_lt[i];
    ans = ((ans + (i - l + 1) * (ppre[r + 2] - ppre[i + 1]) - (r - l + 1) * (ppre[i + 1] - ppre[l])) % MOD + MOD) % MOD;
  }
  return ans;
}

int main() {
  return 0;
}
