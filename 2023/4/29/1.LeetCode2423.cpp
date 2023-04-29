/*************************************************************************
	> File Name: 1.LeetCode2423.cpp
	> Author: 
	> Mail: 
	> Created Time: 2023年04月29日 星期六 09时37分32秒
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

bool equalFrequency(string word) {
  int n = word.size();
  unordered_map<char, int> mp_1;
  for (char c : word)
    mp_1[c]++;
  int m = mp_1.size();
  if (m == 1)
    return true;
  if (((n - 1) % m) && ((n - 1) % (m - 1)))
    return false;
  map<int, int> mp_2;
  for (auto && [c, cnt] : mp_1)
    mp_2[cnt]++;
  if (mp_2.size() > 2)
    return false;
  if (mp_2.size() == 1) {
    if (mp_2.begin()->first == 1)
      return true;
    return false;
  }
  if (mp_2.size() == 2) {
    int x = mp_2.begin()->first;
    int y = prev(mp_2.end())->first;
    if (x == 1 && mp_2[x] == 1)
      return true;
    if (y != x + 1 || mp_2[y] != 1)
      return false;
    return true;
  }
  return false;
}

int main() {
  return 0;
}
