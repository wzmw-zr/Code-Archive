/*************************************************************************
	> File Name: 1.LeetCode1302.cpp
	> Author: 
	> Mail: 
	> Created Time: 2022年08月17日 星期三 09时04分00秒
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

int deepestLeavesSum(TreeNode* root) {
  map<int, int> mp;
  function<void(TreeNode *, int)> dfs = [&](TreeNode *_root, int level) -> void {
    if (!_root) return ;
    mp[level] += _root->val;
    dfs(_root->left, level + 1);
    dfs(_root->right, level + 1);
  };
  dfs(root, 1);
  return mp.rbegin()->second;
}

int main() {
  return 0;
}
