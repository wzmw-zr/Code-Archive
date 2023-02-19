/*************************************************************************
	> File Name: 3.LeetCode6364.cpp
	> Author: 
	> Mail: 
	> Created Time: 2023年02月19日 星期日 11时02分52秒
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

// WA
long MOD = 1e9 + 7;

int squareFreeSubsets(vector<int>& nums) {
  vector<long> cnts(31, 0);
  for (int x : nums) {
    if (x == 1 || pow(int(sqrt(x)), 2) != x)
      cnts[x]++;
  }
  long ans = 1;
  for (int i = 1; i <= 30; i++)
    ans = (ans * (cnts[i] + 1)) % MOD;
  ans = (ans - 1 + MOD) % MOD;
  return ans;
}

int main() {
  return 0;
}
