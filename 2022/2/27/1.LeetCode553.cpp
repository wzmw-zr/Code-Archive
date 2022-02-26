/*************************************************************************
	> File Name: 1.LeetCode553.cpp
	> Author: 
	> Mail: 
	> Created Time: 2022年02月27日 星期日 00时13分44秒
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

using PDS = pair<double, string>;

PDS largest_left(vector<int> &nums, int l, int r);
PDS minist_right(vector<int> &nums, int l, int r);

PDS minist_right(vector<int> &nums, int l, int r) {
  if (l == r) return {nums[l] * 1.0, to_string(nums[l])};
  double val = nums[l];
  for (int i = l + 1; i <= r; i++) val /= nums[i];
  string str = "";
  for (int i = l; i <= r; i++) {
    if (i != l) str += "/";
    str += to_string(nums[i]);
  }
  return {val, str};
}

PDS largest_left(vector<int> &nums, int l, int r) {
  if (l == r) return {nums[l], to_string(nums[l])};
  double mmax = INT32_MIN;
  string ans = "";
  for (int i = l; i < r; i++) {
    auto [left_val, left_str] = largest_left(nums, l, i);
    auto [right_val, right_str] = minist_right(nums, i + 1, r);
    if ((left_val / right_val) > mmax) {
      if (i == l && i == r - 1) ans = left_str + "/" + right_str;
      else if (i == l) ans = left_str + "/(" + right_str + ")";
      else if (i == r - 1) ans = "(" + left_str + ")/" + right_str;
      else ans = "(" + left_str + ")/(" + right_str + ")";
      mmax = left_val / right_val;
    }
  }
  return {mmax, ans};
}

string optimalDivision(vector<int>& nums) {
  int n = nums.size();
  if (n == 1) return to_string(nums[0]);
  double mmax = INT32_MIN;
  string ans = "";
  for (int i = 0; i < n - 1; i++) {
    auto [left_val, left_str] = largest_left(nums, 0, i);
    auto [right_val, right_str] = minist_right(nums, i + 1, n - 1);
    if ((left_val / right_val) > mmax) {
      if (i == 0 && i == n - 2) ans += left_str + "/" + right_str;
      else if (i == 0) ans = left_str + "/(" + right_str + ")";
      else if (i == n - 2) ans = "(" + left_str + ")/" + right_str;
      else ans = "(" + left_str + ")/(" + right_str + ")";
      mmax = left_val / right_val;
    }
  }
  return ans;
}

int main() {
  vector<int> nums;
  int n;
  while (cin >> n) nums.push_back(n);
  cout << optimalDivision(nums) << endl;
  return 0;
}
