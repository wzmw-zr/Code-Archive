/*************************************************************************
	> File Name: 1.LeetCode856.cpp
	> Author: 
	> Mail: 
	> Created Time: 2022年10月09日 星期日 09时03分31秒
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

int dfs(string &s, int l, int r) {
  if ((l + 1 == r) && (s[l] == '(') && (s[r] == ')'))
    return 1;
  int ind = l;
  int cnt = 0;
  do {
    if (s[ind] == '(')
      cnt++;
    else
      cnt--;
    ind++;
  } while (cnt);
  if (ind > r)
    return 2 * dfs(s, l + 1, r - 1);
  return dfs(s, l, ind - 1) + dfs(s, ind, r);
}

int scoreOfParentheses(string s) {
  int l = 0, r = static_cast<int>(s.size()) - 1;
  return dfs(s, l, r);
}

int main() {
  string s;
  cin >> s;
  cout << scoreOfParentheses(s) << endl;
  return 0;
}
