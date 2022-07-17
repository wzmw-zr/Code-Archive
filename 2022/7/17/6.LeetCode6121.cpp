/*************************************************************************
	> File Name: 6.LeetCode6121.cpp
	> Author: 
	> Mail: 
	> Created Time: 2022年07月17日 星期日 14时48分07秒
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

vector<int> smallestTrimmedNumbers(vector<string>& nums, vector<vector<int>>& queries) {
  int m = nums.size();
  int n = nums[0].size();
  int ind = n - 1;
  vector<int> cur_order(m);
  for (int i = 0; i < m; i++) cur_order[i] = i;
  unordered_map<int, vector<int>> orders;
  while (ind >= 0) {
    map<int, vector<int>> mp;
    for (int i = 0; i < m; i++) {
      int t = nums[i][ind] - '0';
      if (!mp.count(t)) mp[t] = vector<int>(0);
      mp[t].push_back(i);
    }
    vector<string> temp;
    vector<int> order;
    for (auto && [x, inds] : mp) {
      for (int idx : inds) {
        order.push_back(cur_order[idx]);
        temp.push_back(nums[idx]);
      }
    }
    cur_order = order;
    orders[n - ind] = order;
    nums = temp;
    ind--;
  }
  vector<int> ans;
  for (auto && q : queries) 
    ans.push_back(orders[q[1]][q[0] - 1]);
  return ans;
}

int main() {
  return 0;
}
