/*************************************************************************
	> File Name: 1.LeetCode1373.cpp
	> Author: 
	> Mail: 
	> Created Time: 2023年05月20日 星期六 09时50分45秒
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
#include <tuple>
using namespace std;

struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;

  TreeNode() = default;
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

using T4I = tuple<int, int, int, int>;

int maxSumBST(TreeNode* _root) {
  int ans = 0;
  function<T4I(TreeNode *)> dfs = [&](TreeNode *root) -> T4I {
    if (!root)
      return {INT32_MAX, INT32_MIN, 0, 1};
    auto [l_min, l_max, l_sum, l_flag] = dfs(root->left);
    auto [r_min, r_max, r_sum, r_flag] = dfs(root->right);
    int flag = 0;
    if (l_flag && r_flag && root->val > l_max && root->val < r_min) {
      flag = 1;
      ans = max(ans, l_sum + r_sum + root->val);
    }
    return {min({l_min, r_min, root->val}), max({l_max, r_max, root->val}), l_sum + r_sum + root->val, flag};
  };
  dfs(_root);
  return ans;
}

int main() {
  return 0;
}
