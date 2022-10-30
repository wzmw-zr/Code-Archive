/*************************************************************************
	> File Name: 1.LeetCode784.cpp
	> Author: 
	> Mail: 
	> Created Time: 2022年10月30日 星期日 09时22分58秒
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

vector<string> letterCasePermutation(string s) {
  unordered_set<string> st;
  function<void(int)> dfs = [&](int ind) -> void {
    if (!s[ind]) {
      st.insert(s);
      return ;
    }
    if (s[ind] >= '0' && s[ind] <= '9') {
      dfs(ind + 1);
      return ;
    }
    char ch1 = s[ind], ch2 = (s[ind] >= 'a' && s[ind] <= 'z') ? s[ind] - 32 : s[ind] + 32;
    dfs(ind + 1);
    s[ind] = ch2;
    dfs(ind + 1);
    s[ind] = ch1;
  };
  dfs(0);
  return vector<string>(st.begin(), st.end());
}

int main() {
  return 0;
}
