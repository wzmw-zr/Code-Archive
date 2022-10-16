/*************************************************************************
	> File Name: 2.LeetCode6204.cpp
	> Author: 
	> Mail: 
	> Created Time: 2022年10月16日 星期日 10时30分35秒
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

int findMaxK(vector<int>& nums) {
  unordered_set<int> st(nums.begin(), nums.end());
  int ans = -1;
  for (int x : st) {
    if (x > 0 && st.count(x * -1)) 
      ans = max(ans, x);
  }
  return ans;
}

int main() {
  return 0;
}
