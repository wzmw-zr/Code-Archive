/*************************************************************************
	> File Name: 1.LeetCode2303.cpp
	> Author: 
	> Mail: 
	> Created Time: 2023年01月23日 星期一 00时48分17秒
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

double calculateTax(vector<vector<int>>& brackets, int income) {
  int pre = 0;
  double ans = 0;
  for (auto && bracket : brackets) {
    int upper = bracket[0], percent = bracket[1];
    ans += 1.0 * (min(income, upper) - pre) * percent / 100;
    pre = min(income, upper);
    if (pre == income)
      break;
  }
  return ans;
}

int main() {
  return 0;
}
