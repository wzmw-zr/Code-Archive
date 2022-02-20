/*************************************************************************
	> File Name: 6.LeetCode6015.cpp
	> Author: 
	> Mail: 
	> Created Time: 2022年02月20日 星期日 11时17分17秒
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

// WA
long long coutPairs(vector<int>& nums, int k) {
  long n = nums.size();
  long can_divide = 0;
  for (int x : nums) {
    if (x % k == 0) can_divide++;
  }
  return can_divide * (n - 1) - can_divide * (can_divide - 1) / 2;
}

int main() {
  return 0;
}
