/*************************************************************************
	> File Name: 1.LeetCode432.cpp
	> Author: 
	> Mail: 
	> Created Time: 2022年03月16日 星期三 00时20分43秒
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

class AllOne {
public:
  unordered_map<string, int> mp;
  map<int, unordered_set<string>> cnt;

  AllOne() {}

  void inc(string key) {
    if (mp.count(key)) {
      cnt[mp[key]].erase(key);
      if (cnt[mp[key]].size() == 0) cnt.erase(mp[key]);
    }
    mp[key]++;
    if (!cnt.count(mp[key])) cnt[mp[key]] = unordered_set<string>();
    cnt[mp[key]].insert(key);
  }

  void dec(string key) {
    if (mp.count(key)) {
      cnt[mp[key]].erase(key);
      if (cnt[mp[key]].size() == 0) cnt.erase(mp[key]);
    }
    if (!(--mp[key])) {
      mp.erase(key);
    } else {
      if (!cnt.count(mp[key])) cnt[mp[key]] = unordered_set<string>();
      cnt[mp[key]].insert(key);
    }
  }

  string getMaxKey() {
    if (cnt.empty()) return "";
    return *((prev(cnt.end())->second).begin());
  }

  string getMinKey() {
    if (cnt.empty()) return "";
    return *(cnt.begin()->second.begin());
  }
};

int main() {
  return 0;
}
