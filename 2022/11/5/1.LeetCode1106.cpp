/*************************************************************************
	> File Name: 1.LeetCode1106.cpp
	> Author: 
	> Mail: 
	> Created Time: 2022年11月05日 星期六 09时54分38秒
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

bool parseBoolExpr(string s) {
  int ind = 0;
  stack<char> st;
  while (s[ind]) {
    if (s[ind] != ')') {
      if (s[ind] != ',') 
        st.push(s[ind]);
    } else {
      vector<int> vals;
      while (st.top() != '(') {
        int val = st.top() == 't' ? 1 : 0;
        vals.push_back(val);
        st.pop();
      }
      st.pop();
      char ops = st.top();
      st.pop();
      if (ops == '!') {
        int val = vals[0];
        val = !val;
        st.push(val == 0 ? 'f' : 't');
      } else if (ops == '&') {
        int val = vals[0];
        for (auto &x : vals) {
          val &= x;
        }
        st.push(val == 0 ? 'f' : 't');
      } else if (ops == '|') {
        int val = vals[0];
        for (auto &x : vals) {
          val |= x;
        }
        st.push(val == 0 ? 'f' : 't');
      }
    }
    ind++;
  }
  return st.top() == 't' ? 1 : 0;
}

int main() {
  return 0;
}
