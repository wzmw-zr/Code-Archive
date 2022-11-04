/*************************************************************************
	> File Name: 1.LeetCode754.cpp
	> Author: 
	> Mail: 
	> Created Time: 2022年11月04日 星期五 10时47分02秒
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

int reachNumber(int target) {
  target = abs(target);
  int n = ceil(sqrt((8.0 * target + 1) / 4) - 0.5);
  int sum = n * (n + 1) / 2;
  if (sum == target)
    return n;
  int dis = sum - target;
  if (dis % 2 == 0)
    return n;
  if ((n + 1) % 2 == 1)
    return n + 1;
  return n + 2;
}

int main() {
  return 0;
}
