/*************************************************************************
	> File Name: 5.LeetCode6223.cpp
	> Author: 
	> Mail: 
	> Created Time: 2022年10月30日 星期日 11时21分22秒
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

// TLE
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

struct Node {
  int val;
  int height;
  Node *fa;
  Node *left;
  Node *right;
  Node() : val(0), height(0), left(nullptr), right(nullptr), fa(nullptr) {}
  Node(int x) : val(x), height(0), left(nullptr), right(nullptr), fa(nullptr) {}
  Node(int x, Node *fa) : val(x), height(0), left(nullptr), right(nullptr), fa(fa) {}
};
 
class Solution {
public:
  vector<int> treeQueries(TreeNode* _root, vector<int>& queries) {
    unordered_map<int, Node *> mp;
    function<Node *(TreeNode *, Node *fa)> rebuild = [&](TreeNode *root, Node *fa) -> Node * {
      if (!root)
        return nullptr;
      Node *node = new Node(root->val, fa);
      Node *left = rebuild(root->left, node);
      Node *right = rebuild(root->right, node);
      node->left = left;
      node->right = right;
      if (left)
        node->height = max(node->height, left->height + 1);
      if (right)
        node->height = max(node->height, right->height + 1);
      return node;
    };
    function<void(Node *)> dfs = [&](Node *root) -> void {
      if (!root)
        return ;
      mp[root->val] = root;
      dfs(root->left);
      dfs(root->right);
    };
    Node *root_t = rebuild(_root, nullptr);
    dfs(root_t);
    vector<int> ans;
    for (int q : queries) {
      Node *node = mp[q];
      vector<Node *> nodes;
      while (node != nullptr) {
        nodes.push_back(node);
        node = node->fa;
      }
      vector<int> heights;
      for (auto x : nodes)
        heights.push_back(x->height);
      int n = nodes.size();
      nodes[0]->height = -1;
      for (int i = 1; i < n; i++) {
        int h_left = nodes[i]->left ? nodes[i]->left->height : -1;
        int h_right = nodes[i]->right ? nodes[i]->right->height : -1;
        nodes[i]->height= max(h_left, h_right) + 1;
      }
      ans.push_back(root_t->height);
      for (int i = 0; i < n; i++)
        nodes[i]->height = heights[i];
    }
    return ans;
  }
};

int main() {
  return 0;
}
