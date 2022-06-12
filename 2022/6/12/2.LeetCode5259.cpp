/*************************************************************************
	> File Name: 2.LeetCode5259.cpp
	> Author: 
	> Mail: 
	> Created Time: 2022年06月12日 星期日 10时31分56秒
 ************************************************************************/

#include <iostream>
#include <string>
#include <vector>
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
  double ans = 0;
  int n = brackets.size();
  int pre = 0;
  for (int i = 0; i < n; i++) {
    int dis = min(income, brackets[i][0]) - pre;
    pre = brackets[i][0];
    ans += 1.0 * dis * brackets[i][1] / 100;
    if (income < brackets[i][0]) break;
  }
  return ans;
}

int main() {
  return 0;
}
