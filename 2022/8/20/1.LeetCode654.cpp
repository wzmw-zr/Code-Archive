/*************************************************************************
	> File Name: 1.LeetCode654.cpp
	> Author: 
	> Mail: 
	> Created Time: 2022年08月20日 星期六 09时02分48秒
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

TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
  int n = nums.size();
  function<TreeNode *(int, int)> dfs = [&](int left, int right) -> TreeNode * {
    if (left > right) 
      return nullptr;
    if (left == right) 
      return new TreeNode(nums[left]);
    int ind = left;
    int mmax = nums[left];
    for (int i = left; i <= right; i++) {
      if (nums[i] > mmax)
        mmax = nums[i], ind = i;
    }
    TreeNode *root = new TreeNode(nums[ind]);
    root->left = dfs(left, ind - 1);
    root->right = dfs(ind + 1, right);
    return root;
  };
  return dfs(0, n - 1);
}

int main() {
  return 0;
}
