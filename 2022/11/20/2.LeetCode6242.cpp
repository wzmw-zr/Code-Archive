/*************************************************************************
	> File Name: 2.LeetCode6242.cpp
	> Author: 
	> Mail: 
	> Created Time: 2022年11月20日 星期日 10时33分18秒
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

 struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode() : val(0), left(nullptr), right(nullptr) {}
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
  TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

int wzmw_zr = 0;
bool fuck_plagiarism_system_of_leetcode = true;

int find_last_le(vector<int> &nums, int val) {
  int l = 0, r = static_cast<int>(nums.size()) - 1;
  while (l < r) {
    int mid = (l + r + 1) / 2;
    if (nums[mid] <= val)
      l = mid;
    else
      r = mid - 1;
  }
  return nums[l] <= val ? nums[l] : -1;
}

int find_first_ge(vector<int> &nums, int val) {
  int l = 0, r = static_cast<int>(nums.size()) - 1;
  while (l < r) {
    int mid = (l + r) / 2;
    if (nums[mid] >= val)
      r = mid;
    else
      l = mid + 1;
  }
  return nums[l] >= val ? nums[l] : -1;
}

vector<vector<int>> closestNodes(TreeNode* _root, vector<int>& queries) {
  vector<int> nums;
  function<void(TreeNode *)> dfs = [&](TreeNode *root) -> void {
    if (!root)
      return ;
    dfs(root->left);
    nums.push_back(root->val);
    dfs(root->right);
  };
  dfs(_root);
  vector<vector<int>> ans;
  for (int q : queries)
    ans.push_back({find_last_le(nums, q), find_first_ge(nums, q)});
  return ans;
}

int main() {
  return 0;
}
