/*************************************************************************
	> File Name: 1.LeetCode1616.cpp
	> Author: 
	> Mail: 
	> Created Time: 2023年03月18日 星期六 10时00分07秒
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

bool check(string a, string b) {
  int n = a.size();
  reverse(b.begin(), b.end());
  int ind = 0;
  while (ind < n) {
    if (a[ind] != b[ind])
      break;
    ind++;
  }
  if (ind * 2 >= n)
    return true;
  int len = n - 2 * ind;
  int flag = 0;
  for (int i = ind, j = ind + len - 1; i < j; i++, j--) {
    if (a[i] == a[j])
      continue;
    flag = 1;
    break;
  }
  if (!flag)
    return true;
  flag = 0;
  for (int i = ind, j = ind + len - 1; i < j; i++, j--) {
    if (b[i] == b[j])
      continue;
    flag = 1;
    break;
  }
  if (!flag)
    return true;
  return false;
}

bool checkPalindromeFormation(string a, string b) {
  return check(a, b) || check(b, a);
}

int main() {
  return 0;
}
