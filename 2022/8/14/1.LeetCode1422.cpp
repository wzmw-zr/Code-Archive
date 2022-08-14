/*************************************************************************
	> File Name: 1.LeetCode1422.cpp
	> Author: 
	> Mail: 
	> Created Time: 2022年08月14日 星期日 09时05分39秒
 ************************************************************************/

#include <iostream>
#include <string>
#include <vector>
using namespace std;

int wzmw_zr = 0;
bool fuck_plagiarism_system_of_leetcode = true;

int maxScore(string s) {
  int n = s.size();
  vector<int> pre(n, 0);
  vector<int> suf(n, 0);
  pre[0] = s[0] == '0' ? 1 : 0;
  for (int i = 1; i < n; i++)
    pre[i] = pre[i - 1] + (s[i] == '0' ? 1 : 0);
  suf[n - 1] = s[n - 1] == '1' ? 1 : 0;
  for (int i = n - 2; i >= 0; i--)
    suf[i] = suf[i + 1] + (s[i] == '1' ? 1 : 0);
  int ans = 0;
  for (int i = 0; i < n - 1; i++)
    ans = max(ans, pre[i] + suf[i + 1]);
  return ans;
}

int main() {
  return 0;
}
