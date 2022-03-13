/*************************************************************************
	> File Name: 2.LeetCode6031.cpp
	> Author: 
	> Mail: 
	> Created Time: 2022年03月13日 星期日 10时32分12秒
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

vector<int> findKDistantIndices(vector<int>& nums, int key, int k) {
  vector<int> inds;
  int n = nums.size();
  for (int i = 0; i < n; i++) {
    if (nums[i] == key) inds.push_back(i);
  }
  set<int> st;
  for (int x : inds) {
    for (int i = max(0, x - k); i <= min(n - 1, x + k); i++) st.insert(i);
  }
  return vector<int>(st.begin(), st.end());
}

int main() {
  return 0;
}
