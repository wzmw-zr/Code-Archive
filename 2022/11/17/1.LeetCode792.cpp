/*************************************************************************
	> File Name: 1.LeetCode792.cpp
	> Author: 
	> Mail: 
	> Created Time: 2022年11月17日 星期四 17时51分42秒
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

int numMatchingSubseq(string s, vector<string>& words) {
  int n = s.size();
  vector<vector<int>> dp(n + 1, vector<int>(26, n));
  for (int i = n - 1; i >= 0; i--) {
    for (int j = 0; j < 26; j++)
      dp[i][j] = dp[i + 1][j];
    dp[i][s[i] - 'a'] = i;
  }
  int ans = 0;
  for (string & word : words) {
    int ind_1 = 0, ind_2 = 0;
    while (ind_1 < n && word[ind_2]) {
      if (s[ind_1] == word[ind_2]) {
        ind_1++, ind_2++;
      } else {
        ind_1 = dp[ind_1][word[ind_2] - 'a'];
      }
    }
    if (!word[ind_2])
      ans++;
  }
  return ans;
}

int main() {
  return 0;
}
