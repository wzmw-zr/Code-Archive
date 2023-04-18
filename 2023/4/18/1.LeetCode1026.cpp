/*************************************************************************
	> File Name: 1.LeetCode1026.cpp
	> Author: 
	> Mail: 
	> Created Time: 2023年04月18日 星期二 09时13分01秒
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
};

using PII = pair<int, int>;

PII dfs(TreeNode *root, int &ans) {
  if (!root)
    return PII(INT32_MAX, INT32_MIN);
  int mmin = INT32_MAX;
  int mmax = INT32_MIN;
  auto [x1, y1] = dfs(root->left, ans);
  if (x1 != INT32_MAX) {
    ans = max(ans, abs(root->val - x1));
    mmin = min(mmin, x1);
  }
  if (y1 != INT32_MIN) {
    ans = max(ans, abs(root->val - y1));
    mmax = max(mmax, y1);
  }
  auto [x2, y2] = dfs(root->right, ans);
  if (x2 != INT32_MAX) {
    ans = max(ans, abs(root->val - x2));
    mmin = min(mmin, x2);
  }
  if (y2 != INT32_MIN) {
    ans = max(ans, abs(root->val - y2));
    mmax = max(mmax, y2);
  }
  mmin = min(mmin, root->val);
  mmax = max(mmax, root->val);
  return PII(min(root->val, mmin), max(root->val, mmax));
}

int maxAncestorDiff(TreeNode* root) {
  int ans = 0;
  dfs(root, ans);
  return ans;
}

int main() {
  return 0;
}
