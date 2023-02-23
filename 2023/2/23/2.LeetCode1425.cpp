/*************************************************************************
	> File Name: 2.LeetCode1425.cpp
	> Author: 
	> Mail: 
	> Created Time: 2023年02月23日 星期四 16时22分13秒
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

int constrainedSubsetSum(vector<int>& nums, int k) {
  int n = nums.size();
  vector<int> dp(n, INT32_MIN);
  multiset<int> st;
  st.insert(0);
  for (int i = 0; i < n; i++) {
    if (st.size() == k + 2)
      st.erase(st.find(dp[i - k - 1]));
    int mmax = *st.rbegin();
    dp[i] = mmax + nums[i];
    st.insert(dp[i]);
  }
  int ans = *max_element(dp.begin(), dp.end());
  return ans;
}

int main() {
  return 0;
}
