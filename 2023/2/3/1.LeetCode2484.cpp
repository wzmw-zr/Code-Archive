/*************************************************************************
	> File Name: 1.LeetCode2484.cpp
	> Author: 
	> Mail: 
	> Created Time: 2023年02月03日 星期五 15时40分04秒
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

int countPalindromes(string s) {
  int n = s.size();
  vector<vector<long>> pre(n + 1, vector<long>(100, 0));
  vector<vector<long>> suf(n + 1, vector<long>(100, 0));

  vector<long> cnts(10, 0);
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < 100; j++)
      pre[i + 1][j] = pre[i][j];
    int x = s[i] - '0';
    for (int j = 0; j < 10; j++)
      pre[i + 1][j * 10 + x] = (pre[i + 1][j * 10 + x] + cnts[j]) % MOD;
    cnts[x]++;
  }

  cnts = vector<long>(10, 0);
  for (int i = n - 1; i >= 0; i--) {
    for (int j = 0; j < 100; j++)
      suf[i][j] = suf[i + 1][j];
    int x = s[i] - '0';
    for (int j = 0; j < 10; j++)
      suf[i][j * 10 + x] = (suf[i][j * 10 + x] + cnts[j]) % MOD;
    cnts[x]++;
  }

  long ans = 0;
  for (int i = 2; i < n - 2; i++) {
    for (int j = 0; j < 100; j++)
      ans = (ans + pre[i][j] * suf[i + 1][j]) % MOD;
  }
  return ans;
}

int main() {
  return 0;
}
