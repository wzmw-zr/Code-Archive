/*************************************************************************
	> File Name: 4.LeetCode6202.cpp
	> Author: 
	> Mail: 
	> Created Time: 2022年10月09日 星期日 10时42分10秒
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

// WA
string robotWithString(string s) {
  stack<char> st;
  string ans = "";
  for (char c : s) {
    while (!st.empty() && st.top() < c) {
      ans += st.top();
      st.pop();
    }
    st.push(c);
  }
  while (!st.empty()) {
    ans += st.top();
    st.pop();
  }
  return ans;
}

int main() {
  return 0;
}
