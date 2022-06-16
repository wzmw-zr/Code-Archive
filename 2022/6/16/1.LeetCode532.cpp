/*************************************************************************
	> File Name: 1.LeetCode532.cpp
	> Author: 
	> Mail: 
	> Created Time: 2022年06月16日 星期四 09时22分12秒
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

int findPairs(vector<int>& nums, int k) {
  map<int, int> mp;
  for (int x : nums) mp[x]++;
  int ans = 0;
  for (auto &&[x, cnt] : mp) {
    if (mp.count(x + k)) {
      if (k == 0) {
        if (mp[x] > 1) ans++;
      } else {
        ans++;
      }
    }
  }
  return ans;
}

int main() {
  return 0;
}
