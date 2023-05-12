/*************************************************************************
	> File Name: 2.LeetCode1330.cpp
	> Author: 
	> Mail: 
	> Created Time: 2023年05月12日 星期五 10时35分03秒
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

int maxValueAfterReverse(vector<int>& nums) {
  int n = nums.size();
  int sum = 0;
  for (int i = 0; i < n - 1; i++)
    sum += abs(nums[i] - nums[i + 1]);
  int max_1 = 0;
  for (int i = 1; i < n - 1; i++) {
    max_1 = max(max_1, abs(nums[0] - nums[i + 1]) - abs(nums[i] - nums[i + 1]));
    max_1 = max(max_1, abs(nums[n - 1] - nums[i - 1]) - abs(nums[i - 1] - nums[i]));
  }
  int mmax = INT32_MIN, mmin = INT32_MAX;
  for (int i = 0; i < n - 1; i++) {
    mmax = max(mmax, min(nums[i], nums[i + 1]));
    mmin = min(mmin, max(nums[i], nums[i + 1]));
  }
  return sum + max(max_1, 2 * (mmax - mmin));
}

int main() {
  return 0;
}
