/*************************************************************************
	> File Name: 3.LeetCode6009.cpp
	> Author: 
	> Mail: 
	> Created Time: 2022年02月27日 星期日 10时32分57秒
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

int minSteps(string s, string t) {
  unordered_map<char, int> mp_1, mp_2;
  for (char c : s) mp_1[c]++;
  for (char c : t) mp_2[c]++;

  int ans = 0;
  for (auto &&[c, cnt] : mp_1) {
    if (!mp_2.count(c)) ans += cnt;
    else {
      if (cnt < mp_2[c]) ans += mp_2[c] - cnt;
    }
  }

  for (auto &&[c, cnt] : mp_2) {
    if (!mp_1.count(c)) ans += cnt;
    else {
      if (cnt < mp_1[c]) ans += mp_1[c] - cnt;
    }
  }

  return ans;
}

int main() {
  return 0;
}
