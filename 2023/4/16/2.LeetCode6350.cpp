/*************************************************************************
	> File Name: 2.LeetCode6350.cpp
	> Author: 
	> Mail: 
	> Created Time: 2023年04月16日 星期日 10时34分10秒
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

int maxDivScore(vector<int>& nums, vector<int>& divisors) {
  sort(divisors.begin(), divisors.end());
  vector<int> cnts;
  int mmax = 0;
  for (int x : divisors) {
    int cnt = 0;
    for (int y : nums) {
      if (y % x == 0)
        cnt++;
    }
    cnts.push_back(cnt);
    mmax = max(mmax, cnt);
  }
  int n = divisors.size();
  for (int i = 0; i < n; i++) {
    if (cnts[i] == mmax)
      return divisors[i];
  }
  return -1;
}

int main() {
  return 0;
}
