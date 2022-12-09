/*************************************************************************
	> File Name: 1.LeetCode1780.cpp
	> Author: 
	> Mail: 
	> Created Time: 2022年12月09日 星期五 09时45分12秒
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

bool checkPowersOfThree(int n) {
  while (n) {
    while (n % 3 == 0)
      n /= 3;
    if (n % 3 == 2)
      return false;
    if (n % 3 == 1)
      n -= 1;
  }
  return true;
}

int main() {
  return 0;
}
