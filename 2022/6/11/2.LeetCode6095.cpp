/*************************************************************************
	> File Name: 2.LeetCode6095.cpp
	> Author: 
	> Mail: 
	> Created Time: 2022年06月11日 星期六 22时31分27秒
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

bool strongPasswordCheckerII(string password) {
  if (password.size() < 8) return false;
  bool flag = 0;
  for (char c : password) {
    if (c >= 'a' && c <= 'z') flag = 1;
  }
  if (!flag) return false;
  flag = 0;
  for (char c : password) {
    if (c >= 'A' && c <= 'Z') flag = 1;
  }
  if (!flag) return false;
  flag = 0;
  for (char c : password) {
    if (c >= '0' && c <= '9') flag = 1;
  }
  if (!flag) return false;
  flag = 0;
  string spec = "!@#$%^&*()-+";
  for (char c : password) {
    for (char x : spec) {
      if (c == x) flag = 1;
    }
  }
  if (!flag) return false;
  flag = 0;
  int n = password.size();
  for (int i = 0; i < n - 1; i++) {
    if (password[i] == password[i + 1]) return false;
  }
  return true;
}

int main() {
  return 0;
}
