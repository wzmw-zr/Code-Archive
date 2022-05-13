/*************************************************************************
	> File Name: 1.LeetCode2530.cpp
	> Author: 
	> Mail: 
	> Created Time: 2022年05月13日 星期五 09时01分42秒
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

bool oneEditAway(string first, string second) {
  if (first == second) return true;
  int m = first.size(), n = second.size();
  if (abs(m - n) >= 2) return false;
  if (m == n) {
    int l = 0, r = n - 1;
    while (l < r && first[l] == second[l]) l++;
    while (l < r && first[r] == second[r]) r--;
    if (l == r) return true;
    return false;
  }
  if (m > n) {
    int l = 0, r = n - 1;
    while (l <= r && first[l] == second[l]) l++;
    while (l <= r && first[r + 1] == second[r]) r--;
    if (l <= r) return false;
    return true;
  } 
  int l = 0, r = m - 1;
  while (l <= r && first[l] == second[l]) l++;
  while (l <= r && first[r] == second[r + 1]) r--;
  if (l <= r) return false;
  return true;
}

int main() {
  return 0;
}
