/*************************************************************************
	> File Name: 3.LeetCode2507.cpp
	> Author: 
	> Mail: 
	> Created Time: 2022年12月19日 星期一 11时07分05秒
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

int smallestValue(int n) {
  vector<int> is_prime(n + 1, 1);
  vector<int> prime_factor(n + 1, 1);
  for (int i = 2; i <= n; i++) {
    if (is_prime[i]) {
      prime_factor[i] = i;
      for (int j = 2; i * j <= n; j++) {
        is_prime[i * j] = 0;
        prime_factor[i * j] = i;
      }
    }
  }
  while (n != 1) {
    int temp = n;
    int sum = 0;
    while (temp != 1) {
      sum += prime_factor[temp];
      temp /= prime_factor[temp];
    }
    if (sum == n)
      return n;
    n = sum;
  }
  return 1;
}

int main() {
  return 0;
}
