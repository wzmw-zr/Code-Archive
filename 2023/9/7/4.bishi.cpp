/*************************************************************************
	> File Name: 4.bishi.cpp
	> Author: 
	> Mail: 
	> Created Time: 2023年09月07日 星期四 19时49分10秒
 ************************************************************************/

#include <iostream>
#include <string>
#include <vector>
#include <stack>
#include <map>
#include <set>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>
using namespace std;


int main() {
  string s;
  cin >> s;
  int n = s.size();
  stack<int> st;
  vector<int> suf(n + 1, 0);
  for (int i = n - 1; i >= 0; i--)
    suf[i] = suf[i + 1] + (s[i] == '0' ? 1 : -1);
  st.push(n);
  long ans = 0;
  for (int i = n - 1; i >= 0; i--) {
    while (!st.empty() && suf[st.top()] < suf[i])
      st.pop();
    ans += st.empty() ? n - i : st.top() - i - 1;
    st.push(i);
  }
  cout << ans << endl;
  return 0;
}
