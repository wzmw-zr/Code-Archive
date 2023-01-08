/*************************************************************************
	> File Name: 1.LeetCode6287.cpp
	> Author: 
	> Mail: 
	> Created Time: 2023年01月07日 星期六 22时31分11秒
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

string categorizeBox(int length, int width, int height, int mass) {
  int flag_1 = 0, flag_2 = 0;
  if ((length >= 1e4) || (width >= 1e4) || (height >= 1e4) || (1L * length * width * height >= 1e9))
    flag_1 = 1;
  flag_2 = mass >= 100 ? 1 : 0;
  if (flag_1 && flag_2)
    return "Both";
  if (!flag_1 && !flag_2)
    return "Neither";
  if (flag_1 && !flag_2)
    return "Bulky";
  return "Heavy";
}

int main() {
  return 0;
}
