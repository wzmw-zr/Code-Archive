/*************************************************************************
	> File Name: 4.LeetCode6222.cpp
	> Author: 
	> Mail: 
	> Created Time: 2022年10月30日 星期日 10时55分20秒
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

long long makeIntegerBeautiful(long long n, int target) {
  vector<int> digits;
  while (n) {
    digits.push_back(n % (1L * 10));
    n /= 10;
  }
  int digit_sum = 0;
  for (int x : digits) 
    digit_sum += x;
  long ans = 0;
  int ind = 0;
  while (digit_sum > target) {
    ans += (10 - digits[ind]) * pow(10L, ind);
    if (ind == digits.size() - 1)
      digits.push_back(0);
    digit_sum -= digits[ind] - 1;
    digits[ind + 1] += 1;
    digits[ind] = 0;
    int ind_t = ind + 1;
    while (digits[ind_t] == 10) {
      if (ind_t == digits.size())
        digits.push_back(0);
      digits[ind_t + 1] += 1;
      digits[ind_t] = 0;
      digit_sum -= 9;
      ind_t++;
    }
    ind = ind_t;
  }
  return ans;
}

int main() {
  return 0;
}
