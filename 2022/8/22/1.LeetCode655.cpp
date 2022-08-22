/*************************************************************************
	> File Name: 1.LeetCode655.cpp
	> Author: 
	> Mail: 
	> Created Time: 2022年08月22日 星期一 09时18分00秒
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
#include <cmath>
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

vector<vector<string>> printTree(TreeNode* _root) {
  function<int(TreeNode *)> dfs = [&](TreeNode *root) -> int {
    if (!root) 
      return -1;
    return max(dfs(root->left), dfs(root->right)) + 1;
  };
  int height = dfs(_root);
  int m = height + 1, n = pow(2, height + 1) - 1;
  vector<vector<string>> ans(m, vector<string>(n, ""));
  function<void(TreeNode *, int, int)> build = [&](TreeNode *root, int r, int c) -> void {
    if (!root) 
      return ;
    ans[r][c] = to_string(root->val);
    build(root->left, r + 1, c - pow(2, height - r - 1));
    build(root->right, r + 1, c + pow(2, height - r - 1));
  };
  build(_root, 0, (n - 1) / 2);
  return ans;
}

int main() {
  return 0;
}
