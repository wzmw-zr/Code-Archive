/*************************************************************************
	> File Name: 4.LeetCode6235.cpp
	> Author: 
	> Mail: 
	> Created Time: 2022年11月13日 星期日 10时45分37秒
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

int calculate(vector<int> &nums) {
  int n = nums.size();
  vector<int> temp = nums;
  sort(temp.begin(), temp.end());
  unordered_map<int, int> graph;
  for (int i = 0; i < n; i++)
    graph[nums[i]] = temp[i];
  int ans = 0;
  function<int(int)> dfs = [&](int x) {
    if (graph[x] == x)
      return 0;
    int next = graph[x];
    graph[x] = x;
    return dfs(next) + 1;
  };
  for (int x : nums) {
    if (graph[x] == x)
      continue;
    ans += dfs(x) - 1;
  }
  return ans;
}

int minimumOperations(TreeNode* _root) {
  vector<vector<int>> levels;
  function<void(TreeNode *, int)> dfs = [&](TreeNode *root, int level) -> void {
    if (!root)
      return ;
    if (levels.size() == level)
      levels.push_back(vector<int>(0));
    levels[level].push_back(root->val);
    dfs(root->left, level + 1);
    dfs(root->right, level + 1);
  };
  dfs(_root, 0);
  int ans = 0;
  for (vector<int> &nums : levels)
    ans += calculate(nums);
  return ans;
}

int main() {
  return 0;
}
