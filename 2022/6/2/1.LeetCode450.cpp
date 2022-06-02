/*************************************************************************
	> File Name: 1.LeetCode450.cpp
	> Author: 
	> Mail: 
	> Created Time: 2022年06月02日 星期四 09时40分05秒
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

TreeNode *predecessor(TreeNode *root) {
  TreeNode *left = root->left;
  while (left->right) left = left->right;
  return left;
}

TreeNode *successor(TreeNode *root) {
  TreeNode *right = root->right;
  while (right->left) right = right->left;
  return right;
}

TreeNode* deleteNode(TreeNode* root, int key) {
  if (!root) return root;
  if (!root->left && !root->right) {
    if (root->val == key) {
      delete root;
      return nullptr;
    }
    return root;
  }
  if (root->val < key) {
    root->right = deleteNode(root->right, key);
  } else if (root->val > key) {
    root->left = deleteNode(root->left, key);
  } else {
    if (root->left) {
      TreeNode *prev = predecessor(root);
      root->val = prev->val;
      root->left = deleteNode(root->left, prev->val);
    } else {
      TreeNode *next = successor(root);
      root->val = next->val;
      root->right = deleteNode(root->right, next->val);
    }
  }
  return root;
}

int main() {
  return 0;
}
