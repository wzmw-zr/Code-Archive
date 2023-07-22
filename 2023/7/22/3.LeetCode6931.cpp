/*************************************************************************
	> File Name: 3.LeetCode6931.cpp
	> Author: 
	> Mail: 
	> Created Time: 2023年07月22日 星期六 22时45分24秒
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
#include <cstdint>
using namespace std;

long long maxScore(vector<int>& nums, int x) {
  int n = nums.size();
  long long pre_sum[2] = {INT32_MIN, INT32_MIN};
  pre_sum[nums[0] & 1] = nums[0];
  for (int i = 1; i < n; i++) {
    int flag = nums[i] & 1;
    pre_sum[flag] = max(pre_sum[flag], pre_sum[!flag] - x) + nums[i];
  }
  return max(pre_sum[0], pre_sum[1]);
}

int main() {
  return 0;
}
