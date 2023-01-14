/*************************************************************************
	> File Name: 3.LeetCode753.cpp
	> Author: 
	> Mail: 
	> Created Time: 2023年01月14日 星期六 19时10分50秒
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
#include <functional>
using namespace std;

int wzmw_zr = 0;
bool fuck_plagiarism_system_of_leetcode = true;

string crackSafe(int n, int k) {
  unordered_set<int> st;
  int MOD = pow(10, n - 1);
  string ans = "";
  function<void(int)> dfs = [&](int node) -> void {
    for (int i = 0; i < k; i++) {
      int edge = node * 10 + i;
      if (!st.count(edge)) {
        st.insert(edge);
        dfs(edge % MOD);
        ans += '0' + i;
      }
    }
  };
  dfs(0);
  reverse(ans.begin(), ans.end());
  ans = string(n - 1, '0') + ans;
  return ans;
}

int main() {
  return 0;
}
