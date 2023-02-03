/*************************************************************************
	> File Name: 2.LeetCode1145.cpp
	> Author: 
	> Mail: 
	> Created Time: 2023年02月03日 星期五 16时46分26秒
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


bool btreeGameWinningMove(TreeNode* _root, int n, int x) {
  vector<vector<int>> cnts(n + 1, vector<int>(2, 0));
  function<int(TreeNode *)> dfs = [&](TreeNode *root) -> int {
    if (!root)
      return 0;
    int left = dfs(root->left);
    int right = dfs(root->right);
    cnts[root->val][0] = left;
    cnts[root->val][1] = right;
    return left + right + 1;
  };
  int cnt = dfs(_root);
  if (cnt == 1)
    return false;
  for (int i = 1; i <= n; i++) {
    if (i == x)
      continue;
    int left = cnts[i][0];
    int right = cnts[i][1];
    int rest = n - left - right - 1;
    if ((left + right + 1) <= rest)
      continue;
    if ((left + rest + 1) <= right)
      continue;
    if ((right + rest + 1) <= left)
      continue;
    return true;
  }
  return false;
}

int main() {
  return 0;
}
