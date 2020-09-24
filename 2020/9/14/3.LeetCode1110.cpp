/*************************************************************************
	> File Name: 3.LeetCode1110.cpp
	> Author:赵睿 
	> Mail: 1767153298@qq.com
	> Created Time: 2020年09月14日 星期一 20时26分17秒
 ************************************************************************/

#include<iostream>
#include<string>
#include<vector>
#include<queue>
#include<stack>
#include<map>
#include<algorithm>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

TreeNode *delNodes(TreeNode *root, vector<int> &to_delete, vector<TreeNode *> &ans) {
    if (!root) return NULL;     
    root->left = delNodes(root->left, to_delete, ans);
    root->right = delNodes(root->right, to_delete, ans);
    for (auto &x : to_delete) {
        if (root->val == x) {
            if (root->left) ans.push_back(root->left);
            if (root->right) ans.push_back(root->right);
            delete root;
            return NULL;
        } 
    }
    return root;
}

vector<TreeNode*> delNodes(TreeNode* root, vector<int>& to_delete) {
    vector<TreeNode *> ans;
    root = delNodes(root, to_delete, ans);
    if (root) ans.push_back(root);
    return ans;
}

int main() {
    return 0;
}
