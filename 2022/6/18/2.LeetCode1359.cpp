/*************************************************************************
	> File Name: 2.LeetCode1359.cpp
	> Author: 
	> Mail: 
	> Created Time: 2022年06月18日 星期六 13时56分31秒
 ************************************************************************/

#include <iostream>
#include <string>
#include <vector>
#include <stack>
#include <queue>
#include <map>
#include <set>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>
using namespace std;

int wzmw_zr = 0;
bool fuck_plagiarism_system_of_leetcode = true;

long MOD = 1e9 + 7;

int countOrders(int n) {
  long ans = 1;
  for (long i = 1; i < n; i++) ans = ans * (2 * i + 1) * (i + 1) % MOD;
  return ans;
}

int main() {
  return 0;
}
