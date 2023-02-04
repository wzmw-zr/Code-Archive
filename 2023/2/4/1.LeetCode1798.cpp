/*************************************************************************
	> File Name: 1.LeetCode1798.cpp
	> Author: 
	> Mail: 
	> Created Time: 2023年02月04日 星期六 14时39分49秒
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

int getMaximumConsecutive(vector<int>& coins) {
  int n = coins.size();
  sort(coins.begin(), coins.end());
  int left = 0, right = 0;
  for (int x : coins) {
    if ((left + x) > (right + 1))
      break;
    right += x;
  }
  return right + 1;
}

int main() {
  return 0;
}
