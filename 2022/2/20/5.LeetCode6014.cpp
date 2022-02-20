/*************************************************************************
	> File Name: 5.LeetCode6014.cpp
	> Author: 
	> Mail: 
	> Created Time: 2022年02月20日 星期日 10时54分18秒
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

string repeatLimitedString(string s, int repeatLimit) {
  map<char, int> mp;
  for (char c : s) mp[c]++;
  auto iter = prev(mp.end());
  string ans = "";
  while (mp.size()) {
    if (iter->second <= repeatLimit) {
      for (int i = 0; i < iter->second; i++) {
        ans += iter->first;
      }
      if (iter != mp.begin()) {
        iter = prev(iter);
        mp.erase(next(iter));
      } else {
        iter = mp.erase(iter);
      }
    } else {
      for (int i = 0; i < repeatLimit; i++) {
        ans += iter->first;
      }
      iter->second -= repeatLimit;
      if (iter == mp.begin()) 
        break;
      ans += prev(iter)->first;
      if (!(--prev(iter)->second)) 
        mp.erase(prev(iter));
    }
  }
  return ans;
}

int main() {
  return 0;
}
