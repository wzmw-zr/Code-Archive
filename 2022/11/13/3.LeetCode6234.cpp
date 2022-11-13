/*************************************************************************
	> File Name: 3.LeetCode6234.cpp
	> Author: 
	> Mail: 
	> Created Time: 2022年11月13日 星期日 10时32分45秒
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

long gcd(long x, long y) {
  return y == 0 ? x : gcd(y, x % y);
}

int subarrayLCM(vector<int>& nums, int k) {
  int n = nums.size();
  int ans = 0;
  for (int i = 0; i < n; i++) {
    long lcm = nums[i];
    for (int j = i; j < n; j++) {
      lcm = (lcm * nums[j]) / gcd(lcm, nums[j] * 1L);
      if (lcm == k)
        ans++;
      if (lcm > k)
        break;
    }
  }
  return ans;
}

int main() {
  return 0;
}
