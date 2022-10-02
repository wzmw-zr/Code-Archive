/*************************************************************************
	> File Name: 5.LeetCode777.cpp
	> Author: 
	> Mail: 
	> Created Time: 2022年10月02日 星期日 11时17分00秒
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

unordered_map<int, int> calculate_pre(string &s) {
  int n = s.size();
  unordered_map<int, int> mp;
  for (int i = 0, j = 0, k = 0; i < n; i++) {
    if (s[i] == 'X') 
      j++;
    if (s[i] == 'L') {
      mp[k] = j;
      k++;
    }
  }
  return mp;
}

unordered_map<int, int> calculate_suf(string &s) {
  int n = s.size();
  unordered_map<int, int> mp;
  for (int i = n - 1, j = 0, k = 0; i >= 0; i--) {
    if (s[i] == 'X')
      j++;
    if (s[i] == 'R') {
      mp[k] = j;
      k++;
    }
  }
  return mp;
}

bool canTransform(string start, string end) {
  string s1 = "", s2 = "";
  for (char c : start) {
    if (c != 'X')
      s1 += c;
  }
  for (char c : end) {
    if (c != 'X')
      s2 += c;
  }
  if (s1 != s2)
    return false;
  int cnt_l = 0, cnt_r = 0;
  for (char c : s1) {
    if (c == 'L')
      cnt_l++;
    if (c == 'R')
      cnt_r++;
  }
  unordered_map<int, int> pre_1 = calculate_pre(start);
  unordered_map<int, int> pre_2 = calculate_pre(end);
  unordered_map<int, int> suf_1 = calculate_suf(start);
  unordered_map<int, int> suf_2 = calculate_suf(end);
  for (int i = 0; i < cnt_l; i++) {
    if (pre_1[i] < pre_2[i])
      return false;
  }
  for (int i = 0; i < cnt_r; i++) {
    if (suf_1[i] < suf_2[i])
      return false;
  }
  return true;
}

int main() {
  return 0;
}
