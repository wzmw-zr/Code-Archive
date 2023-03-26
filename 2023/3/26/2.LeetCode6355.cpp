/*************************************************************************
	> File Name: 2.LeetCode6355.cpp
	> Author: 
	> Mail: 
	> Created Time: 2023年03月26日 星期日 10时39分10秒
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

bool primeSubOperation(vector<int>& nums) {
  int n = nums.size();
  vector<int> is_prime(1010, 0);
  vector<int> primes;
  for (int i = 2; i <= 1000; i++) {
    if (is_prime[i])
      continue;
    primes.push_back(i);
    is_prime[i] = 1;
    for (int j = 2; i * j <= 1000; j++)
      is_prime[i * j] = 1;
  }

  for (int i = 0; i < n; i++) {
    int l = -1, r = primes.size() - 1;
    int diff = nums[i] - (i == 0 ? 0 : nums[i - 1]);
    if (diff <= 0)
      return false;
    while (l < r) {
      int mid = (l + r + 1) / 2;
      if (primes[mid] < diff)
        l = mid;
      else
        r = mid - 1;
    }
    if (l != -1)
      nums[i] -= primes[l];
  }
  return true;
}

int main() {
  return 0;
}
