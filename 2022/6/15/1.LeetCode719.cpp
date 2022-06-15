/*************************************************************************
	> File Name: 1.LeetCode719.cpp
	> Author: 
	> Mail: 
	> Created Time: 2022年06月15日 星期三 09时13分12秒
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

int smallestDistancePair(vector<int>& nums, int k) {
  sort(nums.begin(), nums.end());
  int l = 0, r = 1e6;
  auto bs = [&](int left, int right, int val) -> int {
    int l = left, r = right;
    while (l < r) {
      int mid = (l + r + 1) / 2;
      if (nums[mid] - nums[left] <= val) l = mid;
      else r = mid - 1;
    }
    return l;
  };
  auto calculate = [&](int val) -> int {
    int n = nums.size();
    int ans = 0;
    for (int i = 0; i < n; i++) {
      int ind = bs(i, n - 1, val);
      ans += ind - i;
    }
    return ans;
  };
  while (l < r) {
    int mid = (l + r) / 2;
    int cnt = calculate(mid);
    if (cnt >= k) r = mid;
    else l = mid + 1;
  }
  return l;
}

int main() {
  return 0;
}
