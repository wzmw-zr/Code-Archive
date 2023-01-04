/*************************************************************************
	> File Name: 1.LeetCode1802.cpp
	> Author: 
	> Mail: 
	> Created Time: 2023年01月04日 星期三 15时42分33秒
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

long calc(int n, int ind, int val) {
  long sum = 0;
  int pre = ind + 1;
  int suf = n - ind;

  if (pre >= val) {
    sum += (pre - val) + 1L * (1 + val) * val / 2;
  } else {
    sum += 1L * (val - pre + 1 + val) * pre / 2;
  }
  if (suf >= val) {
    sum += (suf - val) + 1L * (1 + val) * val / 2;
  } else {
    sum += 1L * (val - suf + 1 + val) * suf / 2;
  }
  sum -= val;
  return sum;
}

int maxValue(int n, int index, int maxSum) {
  int l = 1, r = maxSum;
  while (l < r) {
    int mid = (l + r + 1) / 2;
    long sum = calc(n, index, mid);
    if (sum <= 1L * maxSum)
      l = mid;
    else
      r = mid - 1;
  }
  return l;
}

int main() {
  return 0;
}
