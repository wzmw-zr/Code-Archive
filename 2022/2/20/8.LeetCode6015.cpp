/*************************************************************************
	> File Name: 8.LeetCode6015.cpp
	> Author: 
	> Mail: 
	> Created Time: 2022年02月20日 星期日 14时24分42秒
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

int gcd(int x, int y) {
  return y == 0 ? x : gcd(y, x % y);
}

long long coutPairs(vector<int>& nums, int k) {
  unordered_map<long, long> mp;
  long long ans = 0;
  for (int x : nums) mp[gcd(x, k)]++;
  for (auto iter_1 = mp.begin(); iter_1 != mp.end(); iter_1++) {
    for (auto iter_2 = next(iter_1); iter_2 != mp.end(); iter_2++) {
      if ((iter_1->first * iter_2->first) % k) continue;
      ans += iter_1->second * iter_2->second;
    }
    if ((iter_1->first * iter_1->first) % k)  continue;
    ans += iter_1->second * (iter_1->second - 1) / 2;
  }
  return ans;
}

int main() {
  return 0;
}
