/*************************************************************************
	> File Name: 1.LeetCode1754.cpp
	> Author: 
	> Mail: 
	> Created Time: 2022年12月24日 星期六 00时15分33秒
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

// TLE
string largestMerge(string word1, string word2) {
  string ans = "";
  int n = word1.size(), m = word2.size();
  function<void(int, int, string &)> dfs = [&](int x, int y, string &s) -> void {
    if (x == n && y == m) {
      ans = ans.size() ? max(ans, s) : s;
      return ;
    }
    if (x < n && (y == m || word1[x] >= word2[y])) {
      s += word1[x];
      dfs(x + 1, y, s);
      s.pop_back();
      if (word1[x] == word2[y]) {
        s += word2[y];
        dfs(x, y + 1, s);
        s.pop_back();
      }
    } else {
      s += word2[y];
      dfs(x, y + 1, s);
      s.pop_back();
    }
    return ;
  };
  string str = "";
  dfs(0, 0, str);
  return ans;
}

int main() {
  return 0;
}
