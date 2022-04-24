/*************************************************************************
	> File Name: 1.LeetCode6041.cpp
	> Author: 
	> Mail: 
	> Created Time: 2022年04月24日 星期日 14时25分10秒
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

vector<int> intersection(vector<vector<int>>& nums) {
  unordered_set<int> st(nums[0].begin(), nums[0].end());
  for (int i = 1; i < nums.size(); i++) {
    unordered_set<int> temp;
    for (int x : nums[i]) {
      if (st.count(x)) temp.insert(x);
    }
    st = temp;
  }
  vector<int> ans(st.begin(), st.end());
  sort(ans.begin(), ans.end());
  return ans;
}

int main() {
  return 0;
}
