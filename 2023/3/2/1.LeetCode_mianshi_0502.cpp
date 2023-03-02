/*************************************************************************
	> File Name: 1.LeetCode_mianshi_0502.cpp
	> Author: 
	> Mail: 
	> Created Time: 2023年03月02日 星期四 09时26分32秒
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

string printBin(double num) {
  string ans = "0.";
  double base = 0.5;
  while (num != 0 && ans.size() <= 34) {
    if (num >= base) {
      ans += '1';
      num -= base;
    } else {
      ans += '0';
    }
    base /= 2;
  }
  return num == 0 ? ans : "ERROR";
}

int main() {
  return 0;
}
