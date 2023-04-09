/*************************************************************************
	> File Name: 1.LeetCode6361.cpp
	> Author: 
	> Mail: 
	> Created Time: 2023年04月09日 星期日 10时31分33秒
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
#include <cmath>
using namespace std;

int wzmw_zr = 0;
bool fuck_plagiarism_system_of_leetcode = true;

int is_prime(int x) {
  if (x == 1)
    return 0;
  for (int i = 2; i <= int(sqrt(x * 1.0)); i++) {
    if (x % i == 0)
      return 0;
  }
  return 1;
}

int diagonalPrime(vector<vector<int>>& nums) {
  int n = nums.size();
  int ans = 0;
  for (int i = 0; i < n; i++) {
    if (is_prime(nums[i][i]))
      ans = max(ans, nums[i][i]);
    if (is_prime(nums[i][n - 1 - i]))
      ans = max(ans, nums[i][n - 1 - i]);
  }
  return ans;
}

int main() {
  return 0;
}
