/*************************************************************************
	> File Name: 6.LeetCode6127.cpp
	> Author: 
	> Mail: 
	> Created Time: 2022年07月24日 星期日 11时02分37秒
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

long long countExcellentPairs(vector<int>& nums, int k) {
  unordered_set<int> st;
  for (int x : nums) st.insert(x);
  vector<long long> digits(33, 0);
  for (int x : st) {
    int one_cnt = __builtin_popcount(x);
    digits[one_cnt]++;
  }
  long long ans = 0;
  for (int i = 1; i <= 32; i++) {
    if (i + 32 <= k) continue;
    for (int j = max(0, k - i); j <= 32; j++) ans += digits[i] * digits[j];
  }
  return ans;
}

int main() {
  return 0;
}
