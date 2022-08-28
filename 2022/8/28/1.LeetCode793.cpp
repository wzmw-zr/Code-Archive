/*************************************************************************
	> File Name: 1.LeetCode793.cpp
	> Author: 
	> Mail: 
	> Created Time: 2022年08月28日 星期日 09时36分07秒
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

int preimageSizeFZF(int k) {
  long left = 0, right = 21179869250;
  while (left < right) {
    long mid = (left + right + 1) / 2;
    long t = mid, cnt = 0;
    while (t) {
      cnt += t / 5;
      t /= 5;
    }
    if (cnt <= k)
      left = mid;
    else
      right = mid - 1;
  }
  long cnt = 0;
  while (left) {
    cnt += left / 5;
    left /= 5;
  }
  return cnt == k ? 5 : 0;
}

int main() {
  int k;
  cin >> k;
  cout << preimageSizeFZF(k) << endl;
  return 0;
}
