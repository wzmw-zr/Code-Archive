/*************************************************************************
	> File Name: 1.LeetCode1819.cpp
	> Author: 
	> Mail: 
	> Created Time: 2023年01月14日 星期六 09时29分02秒
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

// TLE
int wzmw_zr = 0;
bool fuck_plagiarism_system_of_leetcode = true;

int gcd(int x, int y) {
  return y == 0 ? x : gcd(y, x % y);
}

int countDifferentSubsequenceGCDs(vector<int>& nums) {
  int n = nums.size();
  unordered_set<int> st;
  st.insert(nums[0]);
  for (int i = 1; i < n; i++) {
    unordered_set<int> temp;
    for (int x : st)
      temp.insert(gcd(x, nums[i]));
    for (int x : temp)
      st.insert(x);
    st.insert(nums[i]);
  }
  return st.size();
}

int main() {
  return 0;
}
