/*************************************************************************
	> File Name: 1.LeetCode1147.cpp
	> Author: 
	> Mail: 
	> Created Time: 2023年04月12日 星期三 09时06分47秒
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

int longestDecomposition(string text) {
  if (text.size() == 0)
    return 0;
  int n = text.size();
  int l = 0, r = n - 1, ans = 0;
  while (l < r && text[l] == text[r]) {
    l++, r--, ans += 2;
  }
  if (l > r)
    return ans;
  string s = text.substr(l, r - l + 1);
  int m = r - l + 1;
  vector<int> next(m, -1);
  for (int i = 1; i < m; i++) {
    int ind = next[i - 1];
    while (ind != -1 && s[i] != s[ind + 1])
      ind = next[ind];
    if (s[i] == s[ind + 1])
      next[i] = ind + 1;
  }
  if (next[m - 1] == -1) {
    return ans + 1;
  }
  int ind = next[m - 1];
  while (next[ind] != -1)
    ind = next[ind];
  int len = ind + 1;
  if (len * 2 > m)
    return ans + 1;
  return ans + 2 + longestDecomposition(s.substr(len, m - len * 2));
}

int main() {
  string text;
  cin >> text;
  cout << longestDecomposition(text) << endl;
  return 0;
}
