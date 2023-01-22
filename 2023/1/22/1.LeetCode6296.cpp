/*************************************************************************
	> File Name: 1.LeetCode6296.cpp
	> Author: 
	> Mail: 
	> Created Time: 2023年01月22日 星期日 10时31分14秒
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

int alternateDigitSum(int n) {
  vector<int> nums;
  do {
    nums.push_back(n % 10);
    n /= 10;
  } while (n);
  reverse(nums.begin(), nums.end());
  int flag = 1;
  int ans = 0;
  for (int x : nums) {
    ans += x * flag;
    flag *= -1;
  }
  return ans;
}

int main() {
  return 0;
}
