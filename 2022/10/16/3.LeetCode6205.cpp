/*************************************************************************
	> File Name: 3.LeetCode6205.cpp
	> Author: 
	> Mail: 
	> Created Time: 2022年10月16日 星期日 10时32分56秒
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

int countDistinctIntegers(vector<int>& nums) {
  unordered_set<long> st(nums.begin(), nums.end());
  for (int x : nums) {
    string t = to_string(x);
    reverse(t.begin(), t.end());
    st.insert(stol(t));
  }
  return static_cast<int>(st.size());
}

int main() {
  return 0;
}
