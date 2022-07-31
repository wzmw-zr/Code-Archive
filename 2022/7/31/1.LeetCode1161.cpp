/*************************************************************************
	> File Name: 1.LeetCode1161.cpp
	> Author: 
	> Mail: 
	> Created Time: 2022年07月31日 星期日 09时18分55秒
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
};

void dfs(TreeNode *root, unordered_map<int, int> &mp, int level) {
  if (!root) return;
  mp[level] += root->val;
  dfs(root->left, mp, level + 1);
  dfs(root->right, mp, level + 1);
}

int maxLevelSum(TreeNode* root) {
  unordered_map<int, int> mp;
  dfs(root, mp, 1);
  int max_val = mp[1], level = 1;
  for (auto && [lvl, val] : mp) {
    if (val > max_val) 
      level = lvl, max_val = val;
    else if (val == max_val) 
      level = min(level, lvl);
  }
  return level;
}

int main() {
  return 0;
}
