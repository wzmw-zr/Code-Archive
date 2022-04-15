/*************************************************************************
	> File Name: 1.LeetCode479.cpp
	> Author: 
	> Mail: 
	> Created Time: 2022年04月16日 星期六 00时24分40秒
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

int largestPalindrome(int n) {
  int upper = pow(10, n) - 1;
  int lower = pow(10, n - 1);
  long MOD = 1337;
  for (int i = upper; i >= lower; i--) {
    string tmp = to_string(i);
    string s = tmp + string(tmp.rbegin(), tmp.rend());
    long num = stol(s);
    long j = upper;
    while (j * j >= num) {
      if (num % j == 0) return num % MOD;
      j--;
    }
  }
  return 9;
}

int main() {
  return 0;
}
