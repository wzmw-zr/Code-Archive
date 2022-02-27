/*************************************************************************
	> File Name: 4.LeetCode6010.cpp
	> Author: 
	> Mail: 
	> Created Time: 2022年02月27日 星期日 10时39分49秒
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

long long check(vector<int> &time, long len) {
  long long ans = 0;
  for (long x : time) ans += len / x;
  return ans;
}

long long minimumTime(vector<int>& time, int totalTrips) {
  long long UP = 1e7 + 10;
  UP *= UP;
  long long l = 0, r = UP;
  while (l < r) {
    long mid = (l + r) / 2;
    if (check(time, mid) >= static_cast<long>(totalTrips)) r = mid;
    else l = mid + 1;
  }
  return l;
}

int main() {
  return 0;
}
