/*************************************************************************
	> File Name: 7.LeetCode6325.cpp
	> Author: 
	> Mail: 
	> Created Time: 2023年03月19日 星期日 15时11分03秒
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

long long repairCars(vector<int>& ranks, int cars) {
  long long l = 0, r = INT64_MAX;
  while (l < r) {
    long long mid = (l + r) / 2;
    long long cnt = 0;
    for (int r : ranks)
      cnt += floor(sqrt(mid * 1.0 / r));
    if (cnt >= cars)
      r = mid;
    else
      l = mid + 1;
  }
  return l;
}

int main() {
  return 0;
}
