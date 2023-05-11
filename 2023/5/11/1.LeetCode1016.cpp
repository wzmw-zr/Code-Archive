/*************************************************************************
	> File Name: 1.LeetCode1016.cpp
	> Author: 
	> Mail: 
	> Created Time: 2023年05月11日 星期四 09时25分49秒
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

int to_integer(const string &s) {
  int n = s.size();
  int ans = 0;
  int base = 1;
  for (int i = n - 1; i >= 0; i--) {
    if (s[i] == '1')
      ans += base;
    base *= 2;
  }
  return ans;
}

bool queryString(string s, int n) {
  int m = s.size();
  unordered_set<int> st;
  for (int len = 1; len <= 30; len++) {
    for (int i = 0; i + len - 1 < m; i++) {
      int num = to_integer(s.substr(i, len));
      st.insert(num);
    }
  }
  for (int i = 1; i <= n; i++) {
    if (!st.count(i))
      return false;
  }
  return true;
}

int main() {
  return 0;
}
