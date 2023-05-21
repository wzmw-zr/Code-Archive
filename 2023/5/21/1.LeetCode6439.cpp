/*************************************************************************
	> File Name: 1.LeetCode6439.cpp
	> Author: 
	> Mail: 
	> Created Time: 2023年05月21日 星期日 10时31分04秒
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

int minLength(string s) {
  stack<char> st;
  for (char c : s) {
    if (c == 'B') {
      if (!st.empty() && st.top() == 'A')
        st.pop();
      else
        st.push(c);
    } else if (c == 'D') {
      if (!st.empty() && st.top() == 'C')
        st.pop();
      else
        st.push(c);
    }  else {
      st.push(c);
    }
  }
  return st.size();
}

int main() {
  return 0;
}
