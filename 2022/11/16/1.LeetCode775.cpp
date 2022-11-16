/*************************************************************************
	> File Name: 1.LeetCode775.cpp
	> Author: 
	> Mail: 
	> Created Time: 2022年11月16日 星期三 10时05分17秒
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

long merge_sort(vector<int> &nums, int left, int right) {
  if (left >= right)
    return 0;
  int mid = (left + right) / 2;
  long ans = 0;
  ans += merge_sort(nums, left, mid);
  ans += merge_sort(nums, mid + 1, right);
  int x = left, y = mid + 1;
  vector<int> temp;
  while (x <= mid || y <= right) {
    if ((x <= mid) && ((y > right) || (nums[y] > nums[x]))) {
      temp.push_back(nums[x++]);
    } else if ((y <= right) && ((x > mid) || (nums[y] < nums[x]))){
      temp.push_back(nums[y++]);
      ans += mid - x + 1;
    }
  }
  for (int i = 0; i < (right - left + 1); i++)
    nums[left + i] = temp[i];
  return ans;
}

bool isIdealPermutation(vector<int>& nums) {
  int n = nums.size();
  long local = 0;
  for (int i = 0; i < n - 1; i++)
    local += (nums[i] > nums[i + 1] ? 1 : 0);
  long global = merge_sort(nums, 0, n - 1);
  return local == global;
}

int main() {
  return 0;
}
