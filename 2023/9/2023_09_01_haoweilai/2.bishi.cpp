/*************************************************************************
	> File Name: 2.bishi.cpp
	> Author: 
	> Mail: 
	> Created Time: 2023年09月01日 星期五 19时23分58秒
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
#include <cstdint>
using namespace std;

int main() {
  int x;
  cin >> x;
  string s = to_string(x);
  string mmax = to_string(INT32_MAX);
  string mmin = to_string(INT32_MIN);
  mmin = mmin.substr(1);
  if (x >= 0) {
    while (s.size() > 1 && *s.rbegin() == '0')
      s.pop_back();
    reverse(s.begin(), s.end());
    if (mmax.size() == s.size() && mmax < s) {
      cout << "0" << endl;
    } else {
      cout << s << endl;
    }
  } else {
    s = s.substr(1);
    while (s.size() > 1 && *s.rbegin() == '0')
      s.pop_back();
    reverse(s.begin(), s.end());
    if (mmin.size() == s.size() && mmin < s) {
      cout << "0" << endl;
    } else {
      cout << "-" << s << endl;
    }
  }
  return 0;
}
