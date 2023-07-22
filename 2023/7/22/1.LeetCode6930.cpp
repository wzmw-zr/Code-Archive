/*************************************************************************
	> File Name: 1.LeetCode6930.cpp
	> Author: 
	> Mail: 
	> Created Time: 2023年07月22日 星期六 22时37分33秒
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
#include <numeric>
using namespace std;

bool isGood(vector<int>& nums) {
  int n = nums.size() - 1;
  if (n == 0)
    return false;
  sort(nums.begin(), nums.end());
  vector<int> tmp(n + 1, 0);
  iota(tmp.begin(), tmp.end(), 1);
  tmp[n] = n;
  return nums == tmp;
}

int main() {
  return 0;
}
