/*************************************************************************
	> File Name: 3.bishi.cpp
	> Author: 
	> Mail: 
	> Created Time: 2023年09月01日 星期五 19时35分55秒
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
  int n;
  cin >> n;
  string line_break;
  getline(cin, line_break);
  multiset<int> st;
  for (int i = 0; i < n; i++) {
    string s;
    getline(cin, s);
    int ind = 0;
    while (s[ind]) {
      string str = "";
      while (s[ind] && s[ind] != ',')
        str += s[ind++];
      if (s[ind])
        ind++;
      st.insert(stoi(str));
    }
  }
  int flag = 0;
  for (auto && x : st) {
    if (flag)
      cout << ",";
    cout << x;
    flag = 1;
  }
  cout << endl;
  return 0;
}
