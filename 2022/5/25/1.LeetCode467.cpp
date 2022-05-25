/*************************************************************************
	> File Name: 1.LeetCode467.cpp
	> Author: 
	> Mail: 
	> Created Time: 2022年05月25日 星期三 08时55分11秒
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

int findSubstringInWraproundString(string p) {
  vector<int> dp(26, 0);
  vector<int> len(26, 0);
  int n = p.size();
  dp[p[0] - 'a'] = len[p[0] - 'a'] = 1;
  for (int i = 1; i < n; i++) {
    char pre = (p[i] - 'a' - 1 + 26) % 26 + 'a';
    dp[p[i] - 'a'] = dp[pre - 'a'] + 1;
    len[p[i] - 'a'] = max(len[p[i] - 'a'], dp[p[i] - 'a']);
    for (int j = 0; j < 26; j++) {
      if (j + 'a' == p[i]) continue;
      dp[j] = 0;
    }
  }
  int ans = 0;
  for (int i = 0; i < 26; i++) ans += len[i];
  return ans;
}

int main() {
  string p;
  cin >> p;
  cout << findSubstringInWraproundString(p) << endl;
  return 0;
}
