/*************************************************************************
	> File Name: 5.LeetCode6121.cpp
	> Author: 
	> Mail: 
	> Created Time: 2022年07月17日 星期日 10时51分13秒
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

// TLE
using PIS = pair<int, string>;


vector<int> smallestTrimmedNumbers(vector<string>& nums, vector<vector<int>>& queries) {
  function<bool(PIS &, PIS &)> cmp = [&](PIS &p1, PIS &p2) {
    auto [ind1, s1] = p1;
    auto [ind2, s2] = p2;
    if ((s1.size() && s1[0] == '0') || (s2.size() && s2[0] == '0')) {
      reverse(s1.begin(), s1.end());
      while (s1.size() && *(s1.rbegin()) == '0') s1.pop_back();
      reverse(s1.begin(), s1.end());

      reverse(s2.begin(), s2.end());
      while (s2.size() && *(s2.rbegin()) == '0') s2.pop_back();
      reverse(s2.begin(), s2.end());

      PIS t1(ind1, s1);
      PIS t2(ind2, s2);
      return cmp(t1, t2);
    }
    if (s1.size() < s2.size()) return true;
    if (s1.size() > s2.size()) return false;
    int n = s1.size();
    for (int i = 0; i < n; i++) {
      if (s1[i] > s2[i]) return false;
      if (s1[i] < s2[i]) return true;
    }
    return ind1 < ind2;
  };
  unordered_map<int, vector<PIS>> mp;
  int len = nums[0].size();
  int n = nums.size();
  vector<PIS> vals;
  for (int i = 0; i < n; i++) vals.push_back(PIS(i, ""));
  for (int i = 1; i <= len; i++) {
    for (int j = 0; j < n; j++) {
      vals[j].second = nums[j][len - i] + vals[j].second;
    }
    mp[i] = vals;
  }
  for (auto && [x, arr] : mp) sort(arr.begin(), arr.end(), cmp);
  vector<int> ans;
  for (auto && q : queries) ans.push_back(mp[q[1]][q[0] - 1].first);
  return ans;
}

int main() {
  return 0;
}
