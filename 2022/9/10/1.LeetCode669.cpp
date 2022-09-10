/*************************************************************************
	> File Name: 1.LeetCode669.cpp
	> Author: 
	> Mail: 
	> Created Time: 2022年09月10日 星期六 08时37分09秒
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

TreeNode* trimBST(TreeNode* _root, int low, int high) {
  function<TreeNode *(TreeNode *)> dfs = [&](TreeNode *root) -> TreeNode * {
    if (!root)
      return root;
    root->left = dfs(root->left);
    root->right = dfs(root->right);
    TreeNode *left = root->left;
    TreeNode *right = root->right;
    if (root->val < low) {
      // delete root;
      return right;
    }
    if (root->val > high) {
      // delete root;
      return left;
    }
    return root;
  };
  return dfs(_root);
}

int main() {
  return 0;
}
