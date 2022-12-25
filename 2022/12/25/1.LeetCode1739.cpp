/*************************************************************************
	> File Name: 1.LeetCode1739.cpp
	> Author: 
	> Mail: 
	> Created Time: 2022年12月25日 星期日 09时55分51秒
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

long calc(long n) {
  return n * (n + 1) * (n + 2) / 6;
}

int minimumBoxes(int n) {
  long l = 1, r = 2000;
  while (l < r) {
    int mid = (l + r + 1) / 2;
    int val = calc(mid);
    if (val <= n)
      l = mid;
    else
      r = mid - 1;
  }
  long ans = l * (l + 1) / 2;
  long rest = n - calc(l);
  if (rest == 0)
    return ans;
  l = 1, r += 1;
  while (l < r) {
    int mid = (l + r) / 2;
    int val = mid * (mid + 1) / 2;
    if (val >= rest)
      r = mid;
    else
      l = mid + 1;
  }
  ans += l;
  return ans;
}

int main() {
  return 0;
}
