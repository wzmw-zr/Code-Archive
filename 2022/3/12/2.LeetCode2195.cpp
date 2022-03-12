/*************************************************************************
	> File Name: 2.LeetCode2195.cpp
	> Author: 
	> Mail: 
	> Created Time: 2022年03月12日 星期六 19时32分37秒
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

long long minimalKSum(vector<int>& nums_, int k_) {
  set<int> st(nums_.begin(), nums_.end());
  vector<long long> nums;
  long long k = k_;
  for (int x : st) nums.push_back(x);
  int n = nums.size();
  long long ans = 0;
  long long m = min(nums[0] - 1, k);
  ans += m * (m + 1) / 2;
  k -= m;
  int ind = 0;
  while ((ind < n - 1) && k) {
    long long t = min(nums[ind + 1] - nums[ind] - 1, k);
    ans += (nums[ind] + 1 + nums[ind] + t) * t / 2;
    k -= t;
    ind++;
  }
  if (k) ans += (nums[ind] + 1 + nums[ind] + k) * k / 2;
  return ans;
}

int main() {
  return 0;
}
