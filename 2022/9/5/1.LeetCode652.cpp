/*************************************************************************
	> File Name: 1.LeetCode652.cpp
	> Author: 
	> Mail: 
	> Created Time: 2022年09月05日 星期一 09时24分37秒
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
  TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

vector<TreeNode*> findDuplicateSubtrees(TreeNode* _root) {
  unordered_map<string, vector<TreeNode *>> mp;
  function<string(TreeNode *)> dfs = [&](TreeNode *root) -> string {
    if (root == nullptr)
      return "";
    string left = dfs(root->left);
    string right = dfs(root->right);
    string ans = "(" + left + ")" + to_string(root->val) + "(" + right + ")";
    if (!mp.count(ans))
      mp[ans] = vector<TreeNode *>(0);
    mp[ans].push_back(root);
    return ans;
  };
  dfs(_root);
  vector<TreeNode *> ans;
  for (auto && [str, nodes] : mp) {
    if (nodes.size() > 1)
      ans.push_back(nodes[0]);
  }
  return ans;
}

int main() {
  return 0;
}
