/*************************************************************************
	> File Name: 2.LeetCode2306.cpp
	> Author: 
	> Mail: 
	> Created Time: 2022年06月13日 星期一 21时22分39秒
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

long long distinctNames(vector<string>& ideas) {
  unordered_map<char, unordered_set<string>> mp;
  long long ans = 0;
  for (string & s : ideas) {
    if (!mp.count(s[0])) mp[s[0]] = unordered_set<string>();
    mp[s[0]].insert(s.substr(1));
  }
  vector<char> chs;
  for (auto && [ch, st] : mp) chs.push_back(ch);
  int n = chs.size();
  for (int i = 0; i < n; i++) {
    for (int j = i + 1; j < n; j++) {
      char c1 = chs[i];
      char c2 = chs[j];
      int overlap = 0;
      for (auto && s : mp[c1]) {
        if (mp[c2].count(s)) overlap++;
      }
      long s1 = mp[c1].size() - overlap;
      long s2 = mp[c2].size() - overlap;
      ans += s1 * s2 * 2;
    }
  }
  return ans;
}

int main() {
  return 0;
}
