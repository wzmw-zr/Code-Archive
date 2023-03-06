/*************************************************************************
	> File Name: 1.LeetCode1653.cpp
	> Author: 
	> Mail: 
	> Created Time: 2023年03月06日 星期一 09时55分21秒
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
#include <cstring>
#include <cstdlib>
using namespace std;

int wzmw_zr = 0;
bool fuck_plagiarism_system_of_leetcode = true;

int minimumDeletions(string s) {
  int n = s.size();
  int pre[n + 1], suf[n + 1];
  memset(pre, 0, sizeof(pre));
  memset(suf, 0, sizeof(suf));
  for (int i = 0; i < n; i++)
    pre[i + 1] = pre[i] + (s[i] == 'b' ? 1 : 0);
  for (int i = n - 1; i >= 0; i--)
    suf[i] = suf[i + 1] + (s[i] == 'a' ? 1 : 0);
  int ans = min(pre[n], suf[0]);
  for (int i = 0; i < n - 1; i++)
    ans = min(ans, pre[i + 1] + suf[i + 1]);
  return ans;
}

int main() {
  return 0;
}
