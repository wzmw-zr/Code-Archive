/*************************************************************************
	> File Name: 1.LeetCode687.cpp
	> Author: 
	> Mail: 
	> Created Time: 2022年09月02日 星期五 09时04分20秒
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
#include <functional>
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

int longestUnivaluePath(TreeNode* _root) {
  int ans = 0;
  function<int(TreeNode *)> dfs = [&](TreeNode *root) -> int {
    if (root == nullptr)
      return 0;
    int len = 1, res = 1;
    int left = dfs(root->left), right = dfs(root->right);
    if (root->left && root->left->val == root->val)
      len += left, res = max(res, left + 1);
    if (root->right && root->right->val == root->val)
      len += right, res = max(res, right + 1);
    ans = max(ans, len);
    return res;
  };
  dfs(_root);
  return ans == 0 ? 0 : ans - 1;
}

int main() {
  return 0;
}
