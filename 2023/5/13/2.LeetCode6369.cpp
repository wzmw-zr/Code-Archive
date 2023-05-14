/*************************************************************************
	> File Name: 2.LeetCode6369.cpp
	> Author: 
	> Mail: 
	> Created Time: 2023年05月13日 星期六 23时09分17秒
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

long long maximumOr(vector<int>& nums, int k) {
  int n = nums.size();
  long long ans = 0;
  long long base = 0;
  vector<int> bits(32, 0);
  for (int i = 0; i < n; i++) {
    base |= nums[i];
    for (int j = 0; j < 31; j++) {
      if (nums[i] & (1 << j))
        bits[j]++;
    }
  }
  for (int i = 0; i < n; i++) {
    long long t = base;
    long long x = nums[i];
    x <<= k;
    for (int j = 0; j < 31; j++) {
      if (nums[i] & (1 << j)) {
        if (bits[j] == 1)
          t -= 1 << j;
      }
    }
    ans = max(ans, x | t);
  }
  return ans;
}

int main() {
  return 0;
}
