/*************************************************************************
	> File Name: 2.LeetCode6021.cpp
	> Author: 
	> Mail: 
	> Created Time: 2022年03月19日 星期六 22时42分21秒
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

long long maximumSubsequenceCount(string text, string pattern) {
  int n = text.size();
  vector<int> pre(n + 5, 0);
  vector<int> suf(n + 5, 0);
  for (int i = 0; i < n; i++) {
    pre[i + 1] = pre[i];
    if (text[i] == pattern[0]) pre[i + 1]++;
  }
  for (int i = n - 1; i >= 0; i--) {
    suf[i + 1] = suf[i + 2];
    if (text[i] == pattern[1]) suf[i + 1]++;
  }
  long long ans = 0;
  for (int i = 0; i < n; i++) {
    if (text[i] == pattern[0])  ans += suf[i + 2];
  }
  int mmax = 0;
  for (int i = 0; i < n; i++) {
    mmax = max({mmax, pre[i + 1], suf[i + 1]});
  }
  return ans + mmax;
}

int main() {
  return 0;
}
