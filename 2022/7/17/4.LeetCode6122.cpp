/*************************************************************************
	> File Name: 4.LeetCode6122.cpp
	> Author: 
	> Mail: 
	> Created Time: 2022年07月17日 星期日 10时41分32秒
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
#include <functional>
using namespace std;

int wzmw_zr = 0;
bool fuck_plagiarism_system_of_leetcode = true;

int gcd(int x, int y) {
  return y == 0 ? x : gcd(y, x % y);
}

int minOperations(vector<int>& nums, vector<int>& numsDivide) {
  int max_gcd = numsDivide[0];
  for (int x : numsDivide) max_gcd = gcd(max_gcd, x);
  sort(nums.begin(), nums.end());
  int n = nums.size();
  for (int i = 0; i < n; i++) {
    if (max_gcd % nums[i] == 0) return i;
  }
  return -1;
}

int main() {
  return 0;
}
