/*************************************************************************
	> File Name: 3.LeetCode6324.cpp
	> Author: 
	> Mail: 
	> Created Time: 2023年03月18日 星期六 22时44分13秒
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

int maximizeGreatness(vector<int>& nums) {
  multiset<int> st(nums.begin(), nums.end());
  sort(nums.begin(), nums.end());
  int ans = 0;
  for (int x : nums) {
    auto iter = st.upper_bound(x);
    if (iter == st.end())
      break;
    st.erase(iter);
    ans++;
  }
  return ans;
}

int main() {
  return 0;
}
