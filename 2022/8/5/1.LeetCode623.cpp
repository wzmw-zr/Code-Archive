/*************************************************************************
	> File Name: 1.LeetCode623.cpp
	> Author: 
	> Mail: 
	> Created Time: 2022年08月05日 星期五 09时41分34秒
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

void dfs(TreeNode *root, int lvl, int depth, vector<TreeNode *> &nodes) {
  if (!root) return ;
  if (lvl == depth - 1) {
    nodes.push_back(root);
    return ;
  }
  dfs(root->left, lvl + 1, depth, nodes);
  dfs(root->right, lvl + 1, depth, nodes);
}

TreeNode* addOneRow(TreeNode* root, int val, int depth) {
  if (depth == 1) {
    TreeNode *ans = new TreeNode(val);
    ans->left = root;
    return ans;
  }
  vector<TreeNode *> nodes;
  dfs(root, 1, depth, nodes);
  for (auto && node : nodes) {
    TreeNode *left = new TreeNode(val);
    TreeNode *right = new TreeNode(val);
    left->left = node->left;
    right->right = node->right;
    node->left = left;
    node->right = right;
  }
  return root;
}

int main() {
  return 0;
}
