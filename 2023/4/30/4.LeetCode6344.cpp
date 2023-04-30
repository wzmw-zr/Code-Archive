/*************************************************************************
	> File Name: 4.LeetCode6344.cpp
	> Author: 
	> Mail: 
	> Created Time: 2023年04月30日 星期日 11时31分24秒
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

string smallestBeautifulString(string s, int k) {
  int n = s.size();
  int ind = n - 1;
  while (ind >= 0) {
    if (ind == 0) {
      if (s[ind] < 'a' + k - 1) {
        s[ind]++;
        break;
      }
    } else if (ind == 1) {
      int flag = 0;
      for (char c = s[ind] + 1; c <= 'a' + k - 1; c++) {
        if (c != s[ind - 1]) {
          flag = 1;
          s[ind] = c;
          break;
        }
      }
      if (flag)
        break;
    } else {
      int flag = 0;
      for (char c = s[ind] + 1; c <= 'a' + k - 1; c++) {
        if (c != s[ind - 1] && c != s[ind - 2]) {
          flag = 1;
          s[ind] = c;
          break;
        }
      }
      if (flag)
        break;
    }
    ind--;
  }
  if (ind == -1)
    return "";
  ind++;
  while (ind < n) {
    if (ind == 1) {
      int flag = 0;
      for (char c = 'a'; c <= 'a' + k - 1; c++) {
        if (c != s[ind - 1]) {
          s[ind] = c;
          flag = 1;
          break;
        }
      }
      if (!flag)
        return "";
    } else if (ind >= 2) {
      int flag = 0;
      for (char c = 'a'; c <= 'a' + k - 1; c++) {
        if (c != s[ind - 1] && c != s[ind - 2]) {
          s[ind] = c;
          flag = 1;
          break;
        }
      }
      if (!flag)
        return "";
    }
    ind++;
  }
  return s;
}

int main() {
  return 0;
}
