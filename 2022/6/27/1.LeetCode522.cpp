/*************************************************************************
	> File Name: 1.LeetCode522.cpp
	> Author: 
	> Mail: 
	> Created Time: 2022年06月27日 星期一 08时44分21秒
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

void dfs(int ind, string &s, string &str, unordered_set<string> &st) {
  st.insert(str);
  if (!s[ind]) return ;
  str.push_back(s[ind]);
  dfs(ind + 1, s, str, st);
  str.pop_back();
  dfs(ind + 1, s, str, st);
}

int findLUSlength(vector<string>& strs) {
  int n = strs.size();
  vector<unordered_set<string>> sts;
  for (string &s : strs) {
    unordered_set<string> st;
    string str = "";
    dfs(0, s, str, st);
    sts.push_back(st);
  }
  int ans = -1;
  for (int i = 0; i < n; i++) {
    for (string s : sts[i]) {
      int flag = 1;
      for (int j = 0; j < n; j++) {
        if (i == j) continue;
        if (sts[j].count(s)) {
          flag = 0;
          break;
        }
      }
      if (flag) ans = max(ans, static_cast<int>(s.size()));
    }
  }
  return ans;
}

int main() {
  return 0;
}
