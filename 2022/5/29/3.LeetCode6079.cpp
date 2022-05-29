/*************************************************************************
	> File Name: 3.LeetCode6079.cpp
	> Author: 
	> Mail: 
	> Created Time: 2022年05月29日 星期日 10时38分25秒
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
#include <cmath>
using namespace std;

int wzmw_zr = 0;
bool fuck_plagiarism_system_of_leetcode = true;

bool is_price(string &s) {
  if (s.size() <= 1) return false;
  if (s[0] != '$') return false;
  for (int i = 1; i < s.size(); i++) {
    if (s[i] >= '0' && s[i] <= '9') continue;
    return false;
  }
  return true;
}

string change(string &s, int discount) {
  long double num = stol(s.substr(1));
  num = num / 100 * (100 - discount);
  string res = to_string(num);
  string ans = "$";
  int ind = 0;
  while (res[ind] && res[ind] != '.') ans += res[ind++];
  for (int i = 0; i < 3; i++) ans += res[ind + i];
  return ans;
}

string discountPrices(string sentence, int discount) {
  int ind = 0;
  string ans = "";
  int cnt = 0;
  while (sentence[ind]) {
    string s = "";
    while (sentence[ind] && sentence[ind] != ' ') s += sentence[ind++];
    while (sentence[ind] && sentence[ind] == ' ') ind++;
    if (cnt) ans += " ";
    if (is_price(s)) ans += change(s, discount);
    else ans += s;
    cnt++;
  }
  return ans;
}

int main() {
  return 0;
}
