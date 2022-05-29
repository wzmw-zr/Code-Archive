/*************************************************************************
	> File Name: 1.LeetCode468.cpp
	> Author: 
	> Mail: 
	> Created Time: 2022年05月29日 星期日 09时14分24秒
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

string validIPAddress(string queryIP) {
  int dot_cnt = 0, colon_cnt = 0;
  for (char c : queryIP) {
    if (c == '.') dot_cnt++;
    if (c == ':') colon_cnt++;
  }
  if (dot_cnt == 3 && colon_cnt == 0) {
    int ind = 0;
    auto check = [](string &s) -> bool {
      if (s.size() == 0) return false;
      if (s.size() > 1 && s[0] == '0') return false;
      if (s.size() > 3) return false;
      for (char c : s) {
        if (c >= '0' && c <= '9') continue;
        return false;
      }
      int t = stoi(s);
      if (t < 0 || t > 255) return false;
      return true;
    };
    int cnt = 0;
    while (queryIP[ind]) {
      string s = "";
      while (queryIP[ind] && queryIP[ind] != '.') s += queryIP[ind], ind++;
      if (queryIP[ind]) ind++;
      if (!check(s)) return "Neither";
      cnt++;
    }
    if (cnt == 4) return "IPv4";
    return "Neither";
  } else if (colon_cnt == 7 && dot_cnt == 0) {
    int ind = 0;
    auto check = [](string &s) -> bool {
      if (s.size() == 0 || s.size() > 4) return false;
      for (char c : s) {
        if ((c >= '0' && c <= '9') || (c >= 'a' && c <= 'f') || (c >= 'A' && c <= 'F')) continue;
        return false;
      }
      return true;
    };
    int cnt = 0;
    while (queryIP[ind]) {
      string s = "";
      while (queryIP[ind] && queryIP[ind] != ':') s += queryIP[ind], ind++;
      if (queryIP[ind]) ind++;
      if (!check(s)) return "Neither";
      cnt++;
    }
    if (cnt == 8) return "IPv6";
    return "Neither";
  }
  return "Neither";
}

int main() {
  string queryIP;
  cin >> queryIP;
  cout << validIPAddress(queryIP) << endl;
  return 0;
}
