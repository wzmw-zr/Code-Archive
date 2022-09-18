/*************************************************************************
	> File Name: 4.LeetCode6182.cpp
	> Author: 
	> Mail: 
	> Created Time: 2022年09月18日 星期日 10时34分59秒
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

struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode() : val(0), left(nullptr), right(nullptr) {}
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
  TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};


int wzmw_zr = 0;
bool fuck_plagiarism_system_of_leetcode = true;

void dfs(TreeNode *root, vector<vector<TreeNode *>> &nodes, int level) {
  if (!root)
    return ;
  if (nodes.size() == level)
    nodes.push_back(vector<TreeNode *>(0));
  nodes[level].push_back(root);
  dfs(root->left, nodes, level + 1);
  dfs(root->right, nodes, level + 1);
}

TreeNode* reverseOddLevels(TreeNode* root) {
  vector<vector<TreeNode *>> nodes;
  dfs(root, nodes, 0);
  int level = nodes.size();
  for (int i = 0; i < level; i++) {
    if (!(i & 1))
      continue;
    int l = 0, r = static_cast<int>(nodes[i].size()) - 1;
    while (l < r) 
      swap(nodes[i][l++]->val, nodes[i][r--]->val);
  }
  return root;
}

int main() {
  return 0;
}
