/*************************************************************************
	> File Name: 1.LeetCode449.cpp
	> Author: 
	> Mail: 
	> Created Time: 2022年05月11日 星期三 09时37分55秒
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
  TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Codec {
public:

  // Encodes a tree to a single string.
  string serialize(TreeNode* root) {
    if (!root) return "NULL";
    string ans = "";
    queue<TreeNode *> que;
    que.push(root);
    ans += to_string(root->val) + " ";
    while (!que.empty()) {
      auto temp = que.front();
      que.pop();
      if (temp->left) {
        que.push(temp->left);
        ans += to_string(temp->left->val) + " ";
      } else ans += "NULL ";
      if (temp->right) {
        que.push(temp->right);
        ans += to_string(temp->right->val) + " ";
      } else ans += "NULL ";
    }
    ans.pop_back();
    return ans;
  }

  // Decodes your encoded data to tree.
  TreeNode* deserialize(string data) {
    queue<TreeNode *> que;
    int ind = 0;
    string s;
    while (data[ind] && data[ind] != ' ') s += data[ind++];
    ind++;
    if (s == "NULL") return nullptr;
    TreeNode *root = new TreeNode(stoi(s));
    que.push(root);
    while (!que.empty()) {
      auto temp = que.front();
      que.pop();
      string left = "", right = "";
      while (data[ind] && data[ind] != ' ') left += data[ind++];
      ind++;
      while (data[ind] && data[ind] != ' ') right += data[ind++];
      ind++;
      if (left == "NULL") {
        temp->left = nullptr;
      } else {
        temp->left = new TreeNode(stoi(left));
        que.push(temp->left);
      }
      if (right == "NULL") {
        temp->right = nullptr;
      } else {
        temp->right = new TreeNode(stoi(right));
        que.push(temp->right);
      }
    }
    return root;
  }
};


int main() {
  return 0;
}
