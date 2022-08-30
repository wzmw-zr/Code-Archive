/*************************************************************************
	> File Name: 1.LeetCode998.cpp
	> Author: 
	> Mail: 
	> Created Time: 2022年08月30日 星期二 08时59分12秒
 ************************************************************************/

#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <stack>
#include <set>
#include <map>
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

vector<int> dfs(TreeNode *root) {
  if (!root) 
    return {};
  vector<int> left = dfs(root->left);
  vector<int> right = dfs(root->right);
  vector<int> ans;
  for (int x : left)
    ans.push_back(x);
  ans.push_back(root->val);
  for (int x : right)
    ans.push_back(x);
  return ans;
}

TreeNode *build(vector<int> &nums, int left, int right) {
  if (left > right)
    return nullptr;
  if (left == right)
    return new TreeNode(nums[left]);
  int ind = left;
  for (int i = left; i <= right; i++) {
    if (nums[i] > nums[ind])
      ind = i;
  }
  TreeNode *root = new TreeNode(nums[ind]);
  root->left = build(nums, left, ind - 1);
  root->right = build(nums, ind + 1, right);
  return root;
}


TreeNode* insertIntoMaxTree(TreeNode* root, int val) {
  vector<int> nums = dfs(root);
  nums.push_back(val);
  int n = nums.size();
  return build(nums, 0, n - 1);
}

int main() {
  return 0;
}
