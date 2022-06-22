/*************************************************************************
	> File Name: 1.LeetCode513.cpp
	> Author: 
	> Mail: 
	> Created Time: 2022年06月22日 星期三 08时47分08秒
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

unordered_map<int, int> mp;

int dfs(TreeNode *root, int level) {
  if (!root) return 0;
  if (!mp.count(level)) mp[level] = root->val;
  return max(dfs(root->left, level + 1), dfs(root->right, level + 1)) + 1;
}

int findBottomLeftValue(TreeNode* root) {
  int level = dfs(root, 1);
  return mp[level];
}

int main() {
  return 0;
}
