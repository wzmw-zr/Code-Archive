/*************************************************************************
	> File Name: 1.LeetCode508.cpp
	> Author: 
	> Mail: 
	> Created Time: 2022年06月19日 星期日 09时31分38秒
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

struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode() : val(0), left(nullptr), right(nullptr) {}
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
  TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

long dfs(TreeNode *root, unordered_map<long, int> &mp) {
  if (!root) return 0;
  long left = dfs(root->left, mp);
  long right = dfs(root->right, mp);
  long val = 1L * root->val + left + right;
  mp[val]++;
  return val;
}

vector<int> findFrequentTreeSum(TreeNode* root) {
  unordered_map<long, int> cnts;
  dfs(root, cnts);
  map<int, vector<long>> mp;
  for (auto && [val, cnt] : cnts) {
    if (!mp.count(cnt)) mp[cnt] = vector<long>();
    mp[cnt].push_back(val);
  }
  auto [cnt, ans] = *mp.rbegin();
  vector<int> res(ans.begin(), ans.end());
  return res;
}

int main() {
  return 0;
}
