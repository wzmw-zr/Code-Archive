/*************************************************************************
	> File Name: 1.LeetCode921.cpp
	> Author: 
	> Mail: 
	> Created Time: 2022年10月04日 星期二 09时22分22秒
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

int minAddToMakeValid(string s) {
  stack<char> st;
  for (char c : s) {
    if (st.empty()) {
      st.push(c);
    } else {
      if (c == ')' && st.top() == '(') {
        st.pop();
      } else {
        st.push(c);
      }
    }
  }
  return st.size();
}

int main() {
  return 0;
}
