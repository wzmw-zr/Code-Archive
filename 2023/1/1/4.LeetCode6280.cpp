/*************************************************************************
	> File Name: 4.LeetCode6280.cpp
	> Author: 
	> Mail: 
	> Created Time: 2023年01月01日 星期日 10时48分25秒
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

vector<int> closestPrimes(int left, int right) {
  vector<int> primes(1e6 + 10, 0);
  vector<int> nums;
  for (int i = 2; i <= 1e6; i++) {
    if (primes[i])
      continue;
    primes[i] = 1;
    if (left <= i && i <= right)
      nums.push_back(i);
    for (int j = 2; i * j <= 1e6; j++)
      primes[i * j] = 1;
  }
  if (nums.size() <= 1)
    return {-1, -1};
  int dis = INT32_MAX;
  int n = nums.size();
  for (int i = 0; i < n - 1; i++)
    dis = min(dis, nums[i + 1] - nums[i]);
  for (int i = 0; i < n - 1; i++)
    if (dis == nums[i + 1] - nums[i])
      return {nums[i], nums[i + 1]};
  return {-1, -1};
}

int main() {
  return 0;
}
