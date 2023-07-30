/*************************************************************************
	> File Name: 2.LeetCode6918.cpp
	> Author: 
	> Mail: 
	> Created Time: 2023年07月30日 星期日 10时47分54秒
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
#include <functional>
using namespace std;

string merge(string a, string b, string c) {
  int l1 = a.size(), l2 = b.size(), l3 = c.size();
  int s1 = 0, s2 = 0;
  string d;
  if (a.find(b) == string::npos) {
    for (int i = 1; i <= min(l1, l2); i++) {
      if (a.substr(l1 - i) == b.substr(0, i))
        s1 = i;
    }
    d = a + b.substr(s1);
  } else {
    d = a;
  }
  int l4 = d.size();
  if (d.find(c) == string::npos) {
    for (int i = 1; i <= min(l3, l4); i++) {
      if (d.substr(l4 - i) == c.substr(0, i))
        s2 = i;
    }
    return d + c.substr(s2);
  } 
  return d;
}

string minimumString(string a, string b, string c) {
  vector<string> strs;
  strs.push_back(merge(a, b, c));
  strs.push_back(merge(a, c, b));
  strs.push_back(merge(b, a, c));
  strs.push_back(merge(b, c, a));
  strs.push_back(merge(c, a, b));
  strs.push_back(merge(c, b, a));
  function<bool(string &, string &)> cmp = [&](string &s1, string &s2) {
    return s1.size() == s2.size() ? s1 < s2 : s1.size() < s2.size();
  };
  sort(strs.begin(), strs.end(), cmp);
  return strs[0];
}

int main() {
  return 0;
}
