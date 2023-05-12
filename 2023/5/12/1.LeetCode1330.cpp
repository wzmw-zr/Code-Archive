/*************************************************************************
	> File Name: 1.LeetCode1330.cpp
	> Author: 
	> Mail: 
	> Created Time: 2023年05月12日 星期五 09时36分25秒
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

// TLE
int maxValueAfterReverse(vector<int>& nums) {
  int n = nums.size();
  vector<int> diff(n - 1);
  int sum = 0;
  for (int i = 0; i < n - 1; i++) {
    diff[i] = nums[i + 1] - nums[i];
    sum += abs(diff[i]);
  }
  int ans = sum;
  for (int i = 0; i < n; i++) {
    for (int j = i + 1; j < n; j++) {
      int tmp = sum;
      if (i > 0) {
        tmp -= abs(diff[i - 1]);
        tmp += abs(nums[j] - nums[i - 1]);
      }
      if (j < n - 1) {
        tmp -= abs(diff[j]);
        tmp += abs(nums[j + 1] - nums[i]);
      }
      ans = max(ans, tmp);
    }
  }
  return ans;
}

int main() {
  return 0;
}
