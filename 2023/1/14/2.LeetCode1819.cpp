/*************************************************************************
	> File Name: 2.LeetCode1819.cpp
	> Author: 
	> Mail: 
	> Created Time: 2023年01月14日 星期六 11时23分35秒
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

int gcd(int x, int y) {
  return y == 0 ? x : gcd(y, x % y);
}

int countDifferentSubsequenceGCDs(vector<int>& nums) {
  unordered_set<int> st(nums.begin(), nums.end());
  int mmax = *max_element(nums.begin(), nums.end());
  int ans = 0;
  for (int i = 1; i <= mmax; i++) {
    int val = 0;
    for (int j = 1; i * j <= mmax; j++) {
      if (st.count(i * j)) {
        val = gcd(val, i * j);
        if (val == i) {
          ans++;
          break;
        }
      }
    }
  }
  return ans;
}

int main() {
  return 0;
}
