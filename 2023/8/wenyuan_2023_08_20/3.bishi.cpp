/*************************************************************************
	> File Name: 3.bishi.cpp
	> Author: 
	> Mail: 
	> Created Time: 2023年08月20日 星期日 20时25分20秒
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
  string s;
  int base_pow = 0, base_mult = 1;
  stack<string> st;
  st.push("1");
  map<int, int> mp;
  while (getline(cin, s)) {
    reverse(s.begin(), s.end());
    while (*s.rbegin() == ' ')
      s.pop_back();
    reverse(s.begin(), s.end());
    if (s.find("END") != string::npos) {
      if (st.top() == "n") {
        base_pow--;
      } else {
        base_mult /= stoi(st.top());
      }
      st.pop();
      continue;
    }
    if (s.find("LOOP") != string::npos) {
      string rest = s.substr(5);
      if (rest == "n") {
        base_pow++;
      } else {
        base_mult *= stoi(rest);
      }
      st.push(rest);
      continue;
    } 
    if (s.find("PRINT") != string::npos) {
      int len = s.size() - 6;
      mp[base_pow] += len * base_mult;
    }
  }
  string ans = "";
  for (auto iter = mp.rbegin(); iter != mp.rend(); iter++) {
    if (iter != mp.rbegin())
      ans += "+";
    if (iter->first == 0) {
      ans += to_string(iter->second);
    } else if (iter->first == 1) {
      if (iter->second == 1) {
        ans += "n";
      } else {
        ans += to_string(iter->second) + "*n";
      }
    } else {
      if (iter->second == 1) {
        ans += "n^" + to_string(iter->first);
      } else {
        ans += to_string(iter->second) + "*n^" + to_string(iter->first);
      }
    }
  }
  cout << (ans.size() == 0 ? "0" : ans) << endl;
  return 0;
}
