/*************************************************************************
	> File Name: 1.bishi.cpp
	> Author: 
	> Mail: 
	> Created Time: 2023年10月08日 星期日 15时48分31秒
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

int main() {
  int t;
  cin >> t;
  while (t--) {
    string s;
    cin >> s;
    stack<char> st;
    bool flag = true;
    for (char c : s) {
      if (c == 'a') {
        st.push(c);
      } else {
        if (!st.size()) {
          flag = false;
          break;
        }
        st.pop();
      }
    }
    if (flag)
      flag = st.empty();
    cout << (flag ? "YES" : "NO") << endl;
  }
  return 0;
}
