/*************************************************************************
	> File Name: 2.mianshi.cpp
	> Author: 
	> Mail: 
	> Created Time: 2023年05月06日 星期六 19时22分10秒
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

using PCC = pair<char, char>;

unordered_set<int> special_chars = {'!', '@', '#'};
map<PCC, int> mp = {
  {PCC('!', '!'), 0},
  {PCC('!', '@'), 13},
  {PCC('!', '#'), 4},
  {PCC('@', '@'), 7},
  {PCC('@', '!'), 13},
  {PCC('@', '#'), 20},
  {PCC('#', '#'), 5},
  {PCC('#', '!'), 4},
  {PCC('#', '@'), 20},
};

string add(string s1, string s2) {
  int n = max(s1.size(), s2.size());
  while (s1.size() < n)
    s1 += '0';
  while (s2.size() < n)
    s2 += '0';
  reverse(s1.begin(), s1.end());
  reverse(s2.begin(), s2.end());

  for (int i = 0; i < n; i++) {
    if (s1[i] >= '0' && s1[i] <= '9')
      s1[i] -= '0';
    if (s2[i] >= '0' && s2[i] <= '9')
      s2[i] -= '0';
  }

  int offset = 0;

  for (int i = 0; i < n; i++) {
    if (special_chars.count(s1[i])) {
      int val = mp[PCC(s1[i], s2[i])] + offset;
      s1[i] = val % 10;
      offset = val / 10;
    } else {
      int val = s1[i] + s2[i] + offset;
      s1[i] = val % 10;
      offset = val / 10;
    }
  }

  for (int i = 0; i < n; i++)
    s1[i] += '0';
  reverse(s1.begin(), s1.end());

  if (offset)
    s1 = to_string(offset) + s1;

  return s1;
}

struct Num {
  string _integer;
  string _decimal;

  Num() = default;
  Num(const string &s) {
    int ind = 0;
    while (s[ind] && s[ind] != '.')
      ind++;
    _integer = s.substr(0, ind);
    _decimal = s.substr(min(int(s.size()), ind + 1));
  }

  string operator+(Num &that) {
    string integer_1 = this->_integer, integer_2 = that._integer;
    string decimal_1 = this->_decimal, decimal_2 = that._decimal;

    string decimal = add(decimal_1, decimal_2);
    int n = decimal.size(), m = max(decimal_1.size(), decimal_2.size());
    string off_int = decimal.substr(0, n - m);
    decimal = decimal.substr(n - m);

    string integer = add(integer_1, integer_2);
    off_int = string(integer.size() - off_int.size(), '0') + off_int;
    integer = add(integer, off_int);

    while (decimal.size() && *decimal.rbegin() == '0')
      decimal.pop_back();

    reverse(integer.begin(), integer.end());
    while (integer.size() && *integer.rbegin() == '0')
      integer.pop_back();
    reverse(integer.begin(), integer.end());

    if (decimal.size())
      return integer + "." + decimal;
    return integer;
  }
};

int main() {
  int n;
  string s;
  cin >> n >> s;
  int ind = 0;
  while (s[ind] && s[ind] != '+')
    ind++;
  Num num1 = s.substr(0, ind), num2 = s.substr(ind + 1);
  cout << num1 + num2 << endl;
  return 0;
}
