/*************************************************************************
	> File Name: 3.LeetCode998.cpp
	> Author:赵睿 
	> Mail: 1767153298@qq.com
	> Created Time: 2020年09月12日 星期六 17时18分57秒
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
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

TreeNode* insertIntoMaxTree(TreeNode* root, int val) {
    if (!root) return new TreeNode(val);
    if (root->val == val) return root;
    if (root->val < val) {
        TreeNode *temp = new TreeNode(val);
        temp->left = root;
        return temp;
    }
    if (root->val > val) {
        if (!root->left && !root->right) root->left = insertIntoMaxTree(root->left, val);
        else if (!root->right) root->right = insertIntoMaxTree(root->right, val);
        else {
            if (root->left->val < val) root->left = insertIntoMaxTree(root->left, val);
            else if (root->right->val < val) root->right = insertIntoMaxTree(root->right, val);
            else {
                if ()
            }
        }
    }
}

int main() {
    return 0;
}
