/*************************************************************************
	> File Name: 1.LeetCode1807.cpp
	> Author: 
	> Mail: 
	> Created Time: 2023年01月12日 星期四 09时06分00秒
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

string evaluate(string s, vector<vector<string>>& knowledge) {
  unordered_map<string, string> mp;
  string ans = "";
  for (auto && x : knowledge)
    mp[x[0]] = x[1];
  int ind = 0;
  while (s[ind]) {
    while (s[ind] && s[ind] != '(')
      ans += s[ind++];
    if (!s[ind])
      break;
    ind++;
    string str = "";
    while (s[ind] != ')')
      str += s[ind++];
    ind++;
    if (mp.count(str))
      ans += mp[str];
    else
      ans += "?";
  }
  return ans;
}

int main() {
  return 0;
}
