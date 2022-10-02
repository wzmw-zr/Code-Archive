/*************************************************************************
	> File Name: 2.LeetCode6192.cpp
	> Author: 
	> Mail: 
	> Created Time: 2022年10月02日 星期日 10时30分34秒
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

int commonFactors(int a, int b) {
  int ans = 0;
  for (int i = 1; i <= min(a, b); i++) {
    if ((a % i == 0) && (b % i == 0))
      ans++;
  }
  return ans;
}

int main() {
  return 0;
}
