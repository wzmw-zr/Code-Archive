/*************************************************************************
	> File Name: 2.LeetCode2613.cpp
	> Author: 
	> Mail: 
	> Created Time: 2022年12月28日 星期三 11时24分19秒
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

long gcd(long x, long y) {
  return y == 0 ? x : gcd(y, x % y);
}

int minimizeSet(int divisor1, int divisor2, int uniqueCnt1, int uniqueCnt2) {
  long l = 1, r = INT32_MAX;
  long lcm = 1L * divisor1 * divisor2 / gcd(1L * divisor1, 1L * divisor2);
  while (l < r) {
    long mid = (l + r) / 2;
    long x = mid / divisor1 - mid / lcm;
    long y = mid / divisor2 - mid / lcm;
    int rest = mid - x - y - mid / lcm;
    if (rest >= (max(uniqueCnt1 - y, 0L) + max(uniqueCnt2 - x, 0L)))
      r = mid;
    else
      l = mid + 1;
  }
  return l;
}

int main() {
  return 0;
}
