/*************************************************************************
	> File Name: 1.LeetCode816.cpp
	> Author: 
	> Mail: 
	> Created Time: 2022年11月07日 星期一 09时13分31秒
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

int check(string &s) {
  int n = s.size();
  if (n == 1)
    return 1;
  if (s[0] == '0' && s[1] == '.') {
    if (s[n - 1] == '0')
      return 0;
    return 1;
  }
  if (s[0] == '0')
    return 0;
  int contain_dot = 0;
  for (char c : s)
    contain_dot += c == '.' ? 1 : 0;
  if (contain_dot && s[n - 1] == '0')
    return 0;
  return 1;
}

vector<string> ambiguousCoordinates(string s) {
  int n = s.size();
  s = s.substr(1, n - 2);
  n = n - 2;
  vector<string> ans;
  for (int i = 0; i < n - 1; i++) {
    string s1 = s.substr(0, i + 1);
    string s2 = s.substr(i + 1);
    int m_1 = s1.size(), m_2 = s2.size();
    vector<string> vals_1;
    vector<string> vals_2;
    if (check(s1))
      vals_1.push_back(s1);
    if (check(s2))
      vals_2.push_back(s2);
    for (int j = 0; j < m_1 - 1; j++) {
      string str_1 = s1.substr(0, j + 1);
      string str_2 = s1.substr(j + 1);
      string temp = str_1 + "." + str_2;
      if (check(temp))
        vals_1.push_back(temp);
    }
    for (int j = 0; j < m_2 - 1; j++) {
      string str_1 = s2.substr(0, j + 1);
      string str_2 = s2.substr(j + 1);
      string temp = str_1 + "." + str_2;
      if (check(temp))
        vals_2.push_back(temp);
    }
    for (string & str1 : vals_1) {
      for (string & str2 : vals_2) {
        ans.push_back("(" + str1 + ", " + str2 + ")");
      }
    }
  }
  return ans;
}

int main() {
  return 0;
}
