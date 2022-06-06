/*************************************************************************
	> File Name: 2.LeetCode828.cpp
	> Author: 
	> Mail: 
	> Created Time: 2022年06月06日 星期一 16时01分21秒
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
int uniqueLetterString(string s) {
  int n = s.size();
  vector<int> pre(26, -1);
  vector<int> suf(26, n);
  vector<int> dp1(n), dp2(n);
  for (int i = 0; i < n; i++) {
    int ind = s[i] - 'A';
    dp1[i] = i - pre[ind];
    pre[ind] = i;
  }
  for (int i = n - 1; i >= 0; i--) {
    int ind = s[i] - 'A';
    dp2[i] = suf[ind] - i;
    suf[ind] = i;
  }
  long ans = 0;
  for (int i = 0; i < n; i++) ans = (ans + 1L * dp1[i] * dp2[i]) % MOD;
  return ans;
}

int main() {
  string s;
  cin >> s;
  cout << uniqueLetterString(s) << endl;
  return 0;
}
