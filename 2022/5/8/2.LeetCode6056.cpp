/*************************************************************************
	> File Name: 2.LeetCode6056.cpp
	> Author: 
	> Mail: 
	> Created Time: 2022年05月08日 星期日 10时30分48秒
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

string largestGoodInteger(string num) {
  int n = num.size();
  int digit = -1;
  for (int i = 0; i <= n - 3; i++) {
    if (num[i] == num[i + 1] && num[i] == num[i + 2]) {
      if ((num[i] - '0') > digit) digit = num[i] - '0';
    }
  }
  if (digit == -1) return "";
  return string(3, '0' + digit);
}

int main() {
  return 0;
}
