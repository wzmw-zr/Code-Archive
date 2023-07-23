/*************************************************************************
	> File Name: 3.LeetCode6915.cpp
	> Author: 
	> Mail: 
	> Created Time: 2023年07月23日 星期日 10时36分43秒
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

long long maxArrayValue(vector<int>& _nums) {
  vector<long> nums(_nums.begin(), _nums.end());
  int n = nums.size();
  long ans = nums[n - 1];
  for (int i = n - 2; i >= 0; i--) {
    if (nums[i] <= nums[i + 1])
      nums[i] += nums[i + 1];
    ans = max(ans, nums[i]);
  }
  return ans;
}

int main() {
  return 0;
}
