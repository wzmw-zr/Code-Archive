/*************************************************************************
	> File Name: 5.LeetCode6133.cpp
	> Author: 
	> Mail: 
	> Created Time: 2022年07月31日 星期日 11时22分58秒
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

int maximumGroups(vector<int>& grades) {
  int n = grades.size();
  long l = 1, r = n;
  while (l < r) {
    long mid = (l + r + 1) / 2;
    if (mid * (mid + 1) / 2 <= n) l = mid;
    else r = mid - 1;
  }
  return l;
}

int main() {
  return 0;
}
