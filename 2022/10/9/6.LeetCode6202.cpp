/*************************************************************************
	> File Name: 6.LeetCode6202.cpp
	> Author: 
	> Mail: 
	> Created Time: 2022年10月09日 星期日 15时08分33秒
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

string robotWithString(string s) {
  int n = s.size();
  string str = s;
  for (int i = n - 2; i >= 0; i--)
    str[i] = min(str[i + 1], s[i]);
  str += ('z' + 1);
  stack<char> st;
  string ans = "";
  for (int i = 0; i < n; i++) {
    st.push(s[i]);
    while (!st.empty() && st.top() <= str[i + 1]) {
      ans += st.top();
      st.pop();
    }
  }
  return ans;
}

int main() {
  return 0;
}
