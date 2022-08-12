/*************************************************************************
	> File Name: 1.LeetCode1282.cpp
	> Author: 
	> Mail: 
	> Created Time: 2022年08月12日 星期五 09时04分03秒
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

vector<vector<int>> groupThePeople(vector<int>& groupSizes) {
  unordered_map<int, vector<int>> mp;
  int n = groupSizes.size();
  for (int i = 0; i < n; i++) {
    if (!mp.count(groupSizes[i])) 
      mp[groupSizes[i]] = vector<int>(0);
    mp[groupSizes[i]].push_back(i);
  }
  vector<vector<int>> ans;
  for (auto && [len, vals] : mp) {
    int ind = 0;
    while (len * ind < vals.size()) {
      vector<int> temp(vals.begin() + len * ind, vals.begin() + len * (ind + 1));
      ans.push_back(temp);
      ind++;
    }
  }
  return ans;
}

int main() {
  return 0;
}
