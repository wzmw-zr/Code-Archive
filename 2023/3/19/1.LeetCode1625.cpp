/*************************************************************************
	> File Name: 1.LeetCode1625.cpp
	> Author: 
	> Mail: 
	> Created Time: 2023年03月19日 星期日 09时41分41秒
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

string findLexSmallestString(string s, int a, int b) {
  int n = s.size();
  unordered_set<string> st1;
  while (!st1.count(s)) {
    st1.insert(s);
    s = string(s.end() - b, s.end()) + string(s.begin(), s.end() - b);
  }
  set<string> st2;
  for (auto str : st1) {
    for (int i = 1; i <= 10; i++) {
      for (int j = 1; j < n; j += 2) {
        int x = str[j] - '0';
        str[j] = ((x + a) % 10) + '0';
      }
      st2.insert(str);
      if (b & 1) {
        string s_t = str;
        for (int p = 1; p <= 9; p++) {
          for (int q = 0; q < n; q += 2) {
            int x = s_t[q] - '0';
            s_t[q] = ((x + a) % 10) + '0';
          }
          st2.insert(s_t);
        }
      }
    }
  }
  return *st2.begin();
}

int main() {
  return 0;
}
