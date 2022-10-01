/*************************************************************************
	> File Name: 2.LeetCode6212.cpp
	> Author: 
	> Mail: 
	> Created Time: 2022年10月01日 星期六 22时30分29秒
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
  unordered_map<char, int> mp;
  for (char c : word)
    mp[c]++;
  if (mp.size() == 1)
    return true;
  int flag = 0;
  for (auto && [ch, freq] : mp) {
    if (freq != 1) {
      flag = 1;
      break;
    }
  }
  if (!flag)
    return true;
  int one = 0;
  for (auto && [ch, freq] : mp) 
    one += freq == 1 ? 1 : 0;
  if (one == 1) {
    unordered_set<int> st;
    for (auto && [ch, freq] : mp)
      st.insert(freq);
    return st.size() == 2;
  }
  int n = word.size();
  int ch = mp.size();
  if (n % ch != 1)
    return false;
  int cnt = n / ch;
  for (auto && [c, freq] : mp) {
    if (freq == cnt || freq == (cnt + 1))
      continue;
    return false;
  }
  return true;
}

int main() {
  return 0;
}
