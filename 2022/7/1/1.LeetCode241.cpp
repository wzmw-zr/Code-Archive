/*************************************************************************
	> File Name: 1.LeetCode241.cpp
	> Author: 
	> Mail: 
	> Created Time: 2022年07月01日 星期五 09时32分05秒
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

using PII = pair<int, int>;

map<PII, vector<int>> mp;

vector<int> dfs(int l, int r, vector<int> &nums, vector<char> &ops) {
  if (l == r) return vector<int>({nums[l]});
  PII state(l, r);
  if (mp.count(state)) return mp[state];
  vector<int> ans;
  for (int i = l; i < r; i++) {
    auto left = dfs(l, i, nums, ops);
    auto right = dfs(i + 1, r, nums, ops);
    if (ops[i] == '+') {
      for (auto x : left) {
        for (auto y : right) ans.push_back(x + y);
      }
    } else if (ops[i] == '-') {
      for (auto x : left) {
        for (auto y : right) ans.push_back(x - y);
      }
    } else if (ops[i] == '*') {
      for (auto x : left) {
        for (auto y : right) ans.push_back(x * y);
      }
    }
  }
  return mp[state] = ans;
}

vector<int> diffWaysToCompute(string expression) {
  vector<int> nums;
  vector<char> ops;
  int ind = 0;
  while (expression[ind]) {
    string num = "";
    while (expression[ind] && expression[ind] >= '0' && expression[ind] <= '9') num += expression[ind++];
    nums.push_back(stoi(num));
    if (expression[ind]) ops.push_back(expression[ind++]);
  }
  int n = nums.size();
  vector<int> ans = dfs(0, n - 1, nums, ops);
  return ans;
}

int main() {
  return 0;
}
