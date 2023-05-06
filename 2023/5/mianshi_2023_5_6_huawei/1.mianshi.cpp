/*************************************************************************
	> File Name: 1.mianshi.cpp
	> Author: 
	> Mail: 
	> Created Time: 2023年05月06日 星期六 19时19分39秒
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

unordered_map<char, int> mp = {
  {'0', 0},
  {'1', 1},
  {'2', 2},
  {'3', 3},
  {'4', 4},
  {'5', 5},
  {'6', 6},
  {'7', 7},
  {'8', 8},
  {'9', 9},
  {'A', 10},
  {'B', 11},
  {'C', 12},
  {'D', 13},
  {'E', 14},
  {'F', 15},
};

int main() {
  int n;
  string s;
  cin >> n >> s;

  int m = 4 * s.size();
  string str = string(m, ' ');

  for (int i = 0; s[i]; i++) {
    int x = mp[s[i]];
    str[4 * i] = (x >> 3) & 1;
    str[4 * i + 1] = (x >> 2) & 1;
    str[4 * i + 2] = (x >> 1) & 1;
    str[4 * i + 3] = x & 1;
  }

  for (int i = 0; i < m; i++)
    str[i] += '0';

  str = str.substr(0, n);

  int flag = 0;
  for (int i = 0; i < n; i++) {
    if (str[i] == '0') {
      flag = 1;
      break;
    }
  }

  if (!flag) {
    cout << "0" << endl;
    return 0;
  }

  int flag_1 = 0, len_1 = 0;
  int flag_2 = 0, len_2 = 0;

  for (int l = 1; l <= n; l++) {
    if (!flag_1) {
      string t = str;
      for (int i = 0; i + l < n; i++)
        t[i + l] = max(t[i + l], str[i]);
      int check = 0;
      for (int i = 0; i < n; i++) {
        if (t[i] == '0') {
          check = 1;
          break;
        }
      }
      if (!check)
        flag_1 = 1, len_1 = l;
    }

    if (!flag_2) {
      string t = str;
      for (int i = l; i < n; i++)
        t[i - l] = max(t[i - l], str[i]);
      int check = 0;
      for (int i = 0; i < n; i++) {
        if (t[i] == '0') {
          check = 1;
          break;
        }
      }
      if (!check)
        flag_2 = 1, len_2 = l;
    }
  }

  if (!flag_1 && !flag_2) {
    cout << "0" << endl;
    return 0;
  }

  cout << flag_1 + flag_2 << endl;

  if (flag_1) {
    string s1(n, '0');
    for (int i = 0; i + len_1 < n; i++) {
      if (str[i + len_1] == '0')
        s1[i] = '1';
    }
    cout << "+" << len_1 << endl;
    cout << s1 << endl;
  }
  if (flag_2) {
    string s2(n, '0');
    for (int i = len_2; i < n; i++) {
      if (str[i - len_2] == '0')
        s2[i] = '1';
    }
    cout << "-" << len_2 << endl;
    cout << s2 << endl;
  }
  return 0;
}
