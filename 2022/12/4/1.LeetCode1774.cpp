/*************************************************************************
	> File Name: 1.LeetCode1774.cpp
	> Author: 
	> Mail: 
	> Created Time: 2022年12月04日 星期日 09时55分28秒
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

int find_first_ge(vector<int> &nums, int target) {
  int n = nums.size();
  int l = 0, r = n - 1;
  while (l < r) {
    int mid = (l + r) / 2;
    if (nums[mid] >= target)
      r = mid;
    else
      l = mid + 1;
  }
  return l;
}

int find_last_le(vector<int> &nums, int target) {
  int n = nums.size();
  int l = 0, r = n - 1;
  while (l < r) {
    int mid = (l + r + 1) / 2;
    if (nums[mid] <= target)
      l = mid;
    else
      r = mid - 1;
  }
  return l;
}

int closestCost(vector<int>& baseCosts, vector<int>& toppingCosts, int target) {
  vector<int> vals;
  for (int x : toppingCosts) {
    vals.push_back(x);
    vals.push_back(x);
  }
  int n = vals.size();
  int s = 1;
  vector<int> nums(1 << n, 0);
  while (s < (1 << n)) {
    int ind = __builtin_ctz(s);
    nums[s] = nums[s - (1 << ind)] + vals[ind];
    s++;
  }
  sort(nums.begin(), nums.end());
  int mmin_dis = 0x3f3f3f3f;
  int ans = 0x3f3f3f3f;
  for (int x : baseCosts) {
    int temp = target - x;
    int right = find_first_ge(nums, temp);
    int left = find_last_le(nums, temp);
    int r_dis = abs(x + nums[right] - target);
    if (r_dis < mmin_dis) {
      mmin_dis = r_dis;
      ans = x + nums[right];
    } else if (r_dis == mmin_dis) {
      ans = min(ans, x + nums[right]);
    }

    int l_dis = abs(x + nums[left] - target);
    if (l_dis < mmin_dis) {
      mmin_dis = l_dis;
      ans = x + nums[left];
    } else if (l_dis == mmin_dis) {
      ans = min(ans, x + nums[left]);
    }
  }
  return ans;
}

int main() {
  return 0;
}
