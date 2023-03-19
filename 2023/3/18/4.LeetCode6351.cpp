/*************************************************************************
	> File Name: 4.LeetCode6351.cpp
	> Author: 
	> Mail: 
	> Created Time: 2023年03月18日 星期六 22时48分44秒
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

long long findScore(vector<int>& nums) {
  long long ans = 0;
  int n = nums.size();
  map<int, set<int>> mp;
  vector<int> check(n, 0);
  for (int i = 0; i < n; i++) {
    if (!mp.count(nums[i]))
      mp[nums[i]] = set<int>();
    mp[nums[i]].insert(i);
  }

  while (mp.size()) {
    int val = mp.begin()->first;
    int ind = *((mp.begin()->second).begin());
    ans += val;
    check[ind] = 1;
    mp[val].erase(ind);
    if (!mp[val].size())
      mp.erase(val);
    
    if (ind > 0 && !check[ind - 1]) {
      check[ind - 1] = 1;
      val = nums[ind - 1];
      mp[val].erase(ind - 1);
      if (!mp[val].size())
        mp.erase(val);
    }

    if (ind < n - 1 && !check[ind + 1]) {
      check[ind + 1] = 1;
      val = nums[ind + 1];
      mp[val].erase(ind + 1);
      if (!mp[val].size())
        mp.erase(val);
    }
  }

  return ans;
}

int main() {
  return 0;
}
