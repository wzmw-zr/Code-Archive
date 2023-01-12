/*************************************************************************
	> File Name: 1.LeetCode2287.cpp
	> Author: 
	> Mail: 
	> Created Time: 2023年01月13日 星期五 00时07分01秒
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
#include <functional>
using namespace std;

int wzmw_zr = 0;
bool fuck_plagiarism_system_of_leetcode = true;

int rearrangeCharacters(string s, string target) {
  int ans = 0;
  unordered_map<char, int> mp1, mp2;
  function<bool()> check = [&]() -> bool {
    for (auto && [x, cnt] : mp2) {
      if (mp1[x] >= mp2[x])
        continue;
      return false;
    }
    for (auto && [x, cnt] : mp2)
      mp1[x] -= cnt;
    return true;
  };
  for (char c : target)
    mp2[c]++;
  for (int i = 0; s[i]; i++) {
    mp1[s[i]]++;
    if (check())
      ans++;
  }
  return ans;
}

int main() {
  return 0;
}
