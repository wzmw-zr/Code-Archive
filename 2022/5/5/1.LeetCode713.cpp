/*************************************************************************
	> File Name: 1.LeetCode713.cpp
	> Author: 
	> Mail: 
	> Created Time: 2022年05月05日 星期四 08时29分01秒
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

int numSubarrayProductLessThanK(vector<int>& nums, int k) {
  int l = 0, r = 0, n = nums.size();
  int ans = 0;
  long product = 1;
  while (r < n) {
    product *= nums[r++];
    while (l < r && product >= k) {
      ans += r - l - 1;
      product /= nums[l++];
    }
  }
  ans += (r - l + 1) * (r - l) / 2;
  return ans;
}

int main() {
  return 0;
}
