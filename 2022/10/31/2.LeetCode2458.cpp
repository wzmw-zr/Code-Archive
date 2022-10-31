/*************************************************************************
	> File Name: 2.LeetCode2458.cpp
	> Author: 
	> Mail: 
	> Created Time: 2022年10月31日 星期一 21时14分11秒
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

using PII = pair<int, int>;

vector<int> treeQueries(TreeNode* _root, vector<int>& queries) {
  unordered_map<int, PII> mp;
  vector<int> nums;
  function<int(TreeNode *, int)> dfs = [&](TreeNode *root, int height) -> int {
    if (!root)
      return 0;
    nums.push_back(height);
    int ind = nums.size() - 1;
    int left = dfs(root->left, height + 1);
    int right = dfs(root->right, height + 1);
    mp[root->val] = PII(ind, ind + left + right);
    return left + right + 1;
  };
  dfs(_root, 0);
  int n = nums.size();
  vector<int> pre(n + 1, 0);
  vector<int> suf(n + 1, 0);
  for (int i = 0; i < n; i++)
    pre[i + 1] = max(pre[i], nums[i]);
  for (int i = n - 1; i >= 0; i--)
    suf[i] = max(suf[i + 1], nums[i]);
  vector<int> ans;
  for (int q : queries) {
    int left = mp[q].first;
    int right = mp[q].second;
    ans.push_back(max(pre[left], suf[right + 1]));
  }
  return ans;
}

int main() {
  return 0;
}
