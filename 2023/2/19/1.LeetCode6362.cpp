/*************************************************************************
	> File Name: 1.LeetCode6362.cpp
	> Author: 
	> Mail: 
	> Created Time: 2023年02月19日 星期日 10时31分06秒
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

vector<vector<int>> mergeArrays(vector<vector<int>>& nums1, vector<vector<int>>& nums2) {
  map<int, int> mp;
  for (auto && x : nums1)
    mp[x[0]] += x[1];
  for (auto && x : nums2)
    mp[x[0]] += x[1];
  vector<vector<int>> ans;
  for (auto && [id, val] : mp)
    ans.push_back({id, val});
  return ans;
}

int main() {
  return 0;
}
