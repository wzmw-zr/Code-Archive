/*************************************************************************
	> File Name: 3.LeetCode6164.cpp
	> Author: 
	> Mail: 
	> Created Time: 2022年07月17日 星期日 10时34分20秒
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

int maximumSum(vector<int>& nums) {
  unordered_map<int, vector<int>> mp;
  auto digit_sum = [](int x) {
    int ans = 0;
    while (x) {
      ans += x % 10;
      x /= 10;
    }
    return ans;
  };
  for (int x : nums) {
    int val = digit_sum(x);
    if (!mp.count(val)) mp[val] = vector<int>(0);
    mp[val].push_back(x);
  }
  int ans = -1;
  for (auto && [x, vals] : mp) {
    if (vals.size() == 1) continue;
    sort(vals.begin(), vals.end());
    ans = max(ans, vals[vals.size() - 2] + vals[vals.size() - 1]);
  }
  return ans;
}

int main() {
  return 0;
}
