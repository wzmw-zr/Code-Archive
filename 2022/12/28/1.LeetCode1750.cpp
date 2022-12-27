/*************************************************************************
	> File Name: 1.LeetCode1750.cpp
	> Author: 
	> Mail: 
	> Created Time: 2022年12月28日 星期三 00时13分57秒
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

int minimumLength(string s) {
  int n = s.size();
  int l = 0, r = n - 1;
  while (l < r) {
    if (s[l] != s[r])
      return r - l + 1;
    char c = s[l];
    while (l < r && s[l] == c)
      l++;
    if (l == r)
      return 0;
    while (l < r && s[r] == c)
      r--;
  }
  return r - l + 1;
}

int main() {
  return 0;
}
