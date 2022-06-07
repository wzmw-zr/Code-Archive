/*************************************************************************
	> File Name: 1.LeetCode875.cpp
	> Author: 
	> Mail: 
	> Created Time: 2022年06月07日 星期二 09时30分59秒
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

int minEatingSpeed(vector<int>& piles, int h) {
  int l = 1, r = 1e9;
  while (l < r) {
    int t = 0;
    int mid = (l + r) / 2;
    for (int x : piles) 
      t += x / mid + (x % mid == 0 ? 0 : 1);
    if (t > h) l = mid + 1;
    else r = mid;
  }
  return l;
}

int main() {
  return 0;
}
