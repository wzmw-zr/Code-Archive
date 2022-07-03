/*************************************************************************
	> File Name: 1.LeetCode556.cpp
	> Author: 
	> Mail: 
	> Created Time: 2022年07月03日 星期日 09时38分31秒
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

int nextGreaterElement(int n) {
  vector<int> nums;
  while (n) {
    nums.push_back(n % 10);
    n /= 10;
  }
  int m = nums.size();
  vector<int> inds(m);
  stack<int> st;
  for (int i = m - 1; i >= 0; i--) {
    while (!st.empty() && nums[st.top()] >= nums[i]) st.pop();
    if (st.empty()) inds[i] = i;
    else inds[i] = st.top();
    st.push(i);
  }
  vector<vector<int>> vals(m, vector<int>(0));
  for (int i = 0; i < m; i++) {
    if (inds[i] == i) continue;
    vals[inds[i]].push_back(i);
  }
  auto cmp = [&](int x, int y) {
    return nums[x] == nums[y] ? x < y : nums[x] < nums[y];
  };
  int flag = 0;
  for (int i = 0; i < m; i++) {
    if (!vals[i].size()) continue;
    sort(vals[i].begin(), vals[i].end());
    swap(nums[i], nums[vals[i][0]]);
    sort(nums.begin(), nums.begin() + i, greater<int>());
    flag = 1;
    break;
  }
  if (!flag) return -1;
  string s = "";
  for (int x : nums) s += (x + '0');
  reverse(s.begin(), s.end());
  long ans = stol(s);
  long mmax = INT32_MAX;
  if (ans > mmax) return -1;
  return ans;
}

int main() {
  int n;
  cin >> n;
  cout << nextGreaterElement(n) << endl;
  return 0;
}
