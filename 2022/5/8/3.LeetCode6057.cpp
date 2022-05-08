/*************************************************************************
	> File Name: 3.LeetCode6057.cpp
	> Author: 
	> Mail: 
	> Created Time: 2022年05月08日 星期日 10时35分07秒
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

PII dfs(TreeNode *root, int &cnt) {
  if (!root) return PII(0, 0);
  PII left = dfs(root->left, cnt);
  PII right = dfs(root->right, cnt);
  int sum = left.second + right.second + root->val;
  int num = left.first + right.first + 1;
  if (sum / num == root->val) cnt++;
  return PII(left.first + right.first + 1, left.second + right.second + root->val);
}

int averageOfSubtree(TreeNode* root) {
  int cnt = 0;
  dfs(root, cnt);
  return cnt;
}

int main() {
  return 0;
}
