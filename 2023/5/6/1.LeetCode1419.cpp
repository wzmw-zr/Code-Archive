/*************************************************************************
	> File Name: 1.LeetCode1419.cpp
	> Author: 
	> Mail: 
	> Created Time: 2023年05月06日 星期六 10时31分24秒
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

int minNumberOfFrogs(string croakOfFrogs) {
  string s = "croak";
  unordered_map<char, int> mp = {{'c', 0}, {'r', 0}, {'o', 0}, {'a', 0}, {'k', 0}};
  int ans = 0;
  for (char c : croakOfFrogs) {
    mp[c]++;
    for (char ch : s) {
      if (ch == c)
        break;
      if (mp[c] > mp[ch])
        return -1;
    }
    if (c == 'k') {
      ans = max(ans, mp['c']);
      for (auto && [ch, cnt] : mp)
        mp[ch] -= 1;
    } 
  }
  for (auto && [ch, cnt] : mp)
    if (cnt)
      return -1;
  return ans;
}

int main() {
  return 0;
}
