/*************************************************************************
	> File Name: 1.LeetCode6416.cpp
	> Author: 
	> Mail: 
	> Created Time: 2023年05月07日 星期日 10时30分59秒
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

vector<int> distinctDifferenceArray(vector<int>& nums) {
  int n = nums.size();
  vector<int> ans(n);
  unordered_set<int> st1, st2;
  for (int i = 0; i < n; i++) {
    st1.insert(nums[i]);
    ans[i] = st1.size();
  }
  for (int i = n - 1; i >= 0; i--) {
    ans[i] -= st2.size();
    st2.insert(nums[i]);
  }
  return ans;
}

int main() {
  return 0;
}
