/*************************************************************************
	> File Name: 1.LeetCode919.cpp
	> Author: 
	> Mail: 
	> Created Time: 2022年07月25日 星期一 09时18分21秒
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

class CBTInserter {
public:
  int ind;
  vector<TreeNode *> nodes;

  CBTInserter(TreeNode* root) : ind(1) {
    nodes.push_back(nullptr);
    queue<TreeNode *> que;
    if (root) que.push(root);
    while (!que.empty()) {
      TreeNode *temp = que.front();
      que.pop();
      nodes.push_back(temp);
      if (ind != 1) {
        if (ind & 1) nodes[ind / 2]->right = nodes[ind];
        else nodes[ind / 2]->left = nodes[ind];
      }
      if (temp->left) que.push(temp->left);
      if (temp->right) que.push(temp->right);
      temp->left = temp->right = nullptr;
      ind++;
    }
  }

  int insert(int val) {
    TreeNode *node = new TreeNode(val);
    nodes.push_back(node);
    if (ind != 1) {
      if (ind & 1) nodes[ind / 2]->right = nodes[ind];
      else nodes[ind / 2]->left = nodes[ind];
    }
    int ans = 0;
    if (ind != 1) ans = nodes[ind / 2]->val;
    ind++;
    return ans;
  }

  TreeNode* get_root() {
    if (ind == 1) return nullptr;
    return nodes[1];
  }
};
