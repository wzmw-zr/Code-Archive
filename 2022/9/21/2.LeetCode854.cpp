/*************************************************************************
	> File Name: 2.LeetCode854.cpp
	> Author: 
	> Mail: 
	> Created Time: 2022年09月21日 星期三 10时45分31秒
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
#include <functional>
using namespace std;

int wzmw_zr = 0;
bool fuck_plagiarism_system_of_leetcode = true;

int kSimilarity(string s1, string s2) {
  string str1 = "", str2 = "";
  for (int i = 0; s1[i]; i++) {
    if (s1[i] == s2[i])
      continue;
    str1 += s1[i];
    str2 += s2[i];
  }
  int n = str1.size();
  if (n == 0)
    return 0;
  int ans = n - 1;
  function<void(int, int)> dfs = [&](int pos, int cost) {
    if (cost > ans)
      return ;
    while (str1[pos] && str1[pos] == str2[pos])
      pos++;
    if (pos == n) {
      ans = min(ans, cost);
      return ;
    }
    for (int i = pos + 1; i < n; i++) {
      if (str1[i] == str2[pos]) {
        swap(str1[i], str1[pos]);
        dfs(pos + 1, cost + 1);
        swap(str1[i], str1[pos]);
      }
    }
  };
  dfs(0, 0);
  return ans;
}

int main() {
  return 0;
}
