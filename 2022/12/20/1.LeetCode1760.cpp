/*************************************************************************
	> File Name: 1.LeetCode1760.cpp
	> Author: 
	> Mail: 
	> Created Time: 2022年12月20日 星期二 10时30分56秒
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

int minimumSize(vector<int>& nums, int maxOperations) {
  int l = 1, r = 1e9;
  while (l < r) {
    int mid = (l + r) / 2;
    int ops = 0;
    for (int x : nums)
      ops += (x - 1) / mid;
    if (ops <= maxOperations)
      r = mid;
    else
      l = mid + 1;
  }
  return l;
}

int main() {
  return 0;
}
