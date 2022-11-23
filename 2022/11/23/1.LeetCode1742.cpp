/*************************************************************************
	> File Name: 1.LeetCode1742.cpp
	> Author: 
	> Mail: 
	> Created Time: 2022年11月23日 星期三 09时24分56秒
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

int countBalls(int lowLimit, int highLimit) {
  unordered_map<int, int> mp;
  for (int i = lowLimit; i <= highLimit; i++) {
    int x = i;
    int sum = 0;
    while (x) {
      sum += x % 10;
      x /= 10;
    }
    mp[sum]++;
  }
  int mmax = 0;
  for (auto && [x, cnt] : mp)
    mmax = max(mmax, cnt);
  return mmax;
}

int main() {
  return 0;
}
