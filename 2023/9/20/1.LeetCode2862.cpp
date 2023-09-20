/*************************************************************************
	> File Name: 1.LeetCode2862.cpp
	> Author: 
	> Mail: 
	> Created Time: 2023年09月20日 星期三 10时34分31秒
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


long long maximumSum(vector<int>& nums) {
  int n = nums.size();
  vector<long> rest(n + 1, 0);
  for (long i = 1; i <= n; i++) {
    if (rest[i])
      continue;
    for (long j = 1; i * j * j <= n; j++)
      rest[i * j * j] = i;
  }
  vector<long> sum(n + 1, 0);
  for (int i = 1; i <= n; i++)
    sum[rest[i]] += nums[i - 1];
  return *max_element(sum.begin(), sum.end());
}


int main() {
  return 0;
}
