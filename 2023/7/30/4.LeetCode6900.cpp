/*************************************************************************
	> File Name: 4.LeetCode6900.cpp
	> Author: 
	> Mail: 
	> Created Time: 2023年07月30日 星期日 11时38分12秒
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
#include <cstdint>
using namespace std;

int countCompleteSubarrays(vector<int>& nums) {
  unordered_set<int> st1(nums.begin(), nums.end());
  unordered_map<int, vector<int>> pos;
  for (int x : st1)
    pos[x] = vector<int>(0);
  unordered_set<int> st2;
  int ans = 0;
  for (int i = 0; i < nums.size(); i++) {
    st2.insert(nums[i]);
    pos[nums[i]].push_back(i);
    if (st1.size() != st2.size())
      continue;
    int mmin_ind = INT32_MAX;
    for (auto && [x, inds] : pos)
      mmin_ind = min(mmin_ind, inds[inds.size() - 1]);
    ans += mmin_ind + 1;
  }
  return ans;
}

int main() {
  return 0;
}
