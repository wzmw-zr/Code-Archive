/*************************************************************************
	> File Name: 1.LeetCode2562.cpp
	> Author: 
	> Mail: 
	> Created Time: 2022年05月16日 星期一 09时24分25秒
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
  TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

void dfs(TreeNode *root, vector<TreeNode *> &nodes) {
  if (!root) return ;
  dfs(root->left, nodes);
  nodes.push_back(root);
  dfs(root->right, nodes);
}

TreeNode* inorderSuccessor(TreeNode* root, TreeNode* p) {
  vector<TreeNode *> nodes;
  dfs(root, nodes);
  int n = nodes.size();
  int ind = 0;
  while (ind < n) {
    if (nodes[ind] == p) break;
    ind++;
  }
  if (ind == n - 1) return nullptr;
  return nodes[ind + 1];
}

int main() {
  return 0;
}
