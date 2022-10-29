/*************************************************************************
	> File Name: 1.LeetCode1773.cpp
	> Author: 
	> Mail: 
	> Created Time: 2022年10月29日 星期六 09时31分15秒
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

int countMatches(vector<vector<string>>& items, string ruleKey, string ruleValue) {
  unordered_map<string, int> mp = {
    {"type", 0}, {"color", 1}, {"name", 2}
  };
  int ind = mp[ruleKey];
  int ans = 0;
  for (auto && item : items) {
    if (item[ind] == ruleValue)
      ans++;
  }
  return ans;
}

int main() {
  return 0;
}
