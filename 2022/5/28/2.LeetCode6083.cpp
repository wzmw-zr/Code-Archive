/*************************************************************************
	> File Name: 2.LeetCode6083.cpp
	> Author: 
	> Mail: 
	> Created Time: 2022年05月28日 星期六 22时31分07秒
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

bool digitCount(string num) {
  int n = num.size();
  unordered_map<int, int> cnts;
  for (char c : num) cnts[c - '0']++;
  for (int i = 0; i < n; i++) {
    if (cnts[i] == num[i] - '0') continue;
    return false;
  }
  return true;
}

int main() {
  return 0;
}
