/*************************************************************************
	> File Name: 4.LeetCode6154.cpp
	> Author: 
	> Mail: 
	> Created Time: 2022年08月21日 星期日 10时53分30秒
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
  TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

int amountOfTime(TreeNode* _root, int start) {
  unordered_map<int, vector<int>> mp;
  function<void(TreeNode *)> dfs = [&](TreeNode *root) -> void {
    if (!root)
      return ;
    if (!mp.count(root->val))
      mp[root->val] = vector<int>(0);
    if (root->left && !mp.count(root->left->val))
      mp[root->left->val] = vector<int>(0);
    if (root->right && !mp.count(root->right->val))
      mp[root->right->val] = vector<int>(0);
    if (root->left) {
      mp[root->val].push_back(root->left->val);
      mp[root->left->val].push_back(root->val);
    }
    if (root->right) {
      mp[root->val].push_back(root->right->val);
      mp[root->right->val].push_back(root->val);
    }
    dfs(root->left);
    dfs(root->right);
  };
  dfs(_root);
  unordered_map<int, int> check;
  for (auto && [val, _]  : mp) 
    check[val] = 0;
  int minite = 0;
  queue<int> que;
  que.push(start);
  check[start] = 1;
  while (!que.empty()) {
    int len = que.size();
    for (int i = 0; i < len; i++) {
      int val = que.front();
      que.pop();
      for (int next : mp[val]) {
        if (check[next])
          continue;
        que.push(next);
        check[next] = 1;
      }
    }
    minite++;
  }
  return minite - 1;
}

int main() {
  return 0;
}
