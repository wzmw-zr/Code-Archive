/*************************************************************************
	> File Name: 1.LeetCode1822.cpp
	> Author: 
	> Mail: 
	> Created Time: 2022年10月27日 星期四 09时22分38秒
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

int arraySign(vector<int>& nums) {
  int ans = 1;
  for (int x : nums) {
    if (x == 0)
      return 0;
    if (x > 0)
      continue;
    ans *= -1;
  }
  return ans;
}

int main() {
  return 0;
}
