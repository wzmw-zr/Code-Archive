/*************************************************************************
	> File Name: 1.LeetCode938.cpp
	> Author: 
	> Mail: 
	> Created Time: 2021年04月27日 星期二 00时02分36秒
 ************************************************************************/

#include<iostream>
#include<string>
#include<vector>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int val) : val(val), left(nullptr), right(nullptr) {}
};

void dfs(TreeNode *root, int &low, int &high, int &sum) {
    if (!root) return ;
    if (root->val >= low && root->val <= high) sum += root->val;
    dfs(root->left, low, high, sum);
    dfs(root->right, low, high, sum);
}

int rangeSumBST(TreeNode* root, int low, int high) {
    int sum = 0;
    dfs(root, low, high, sum);
    return sum;
}

int main() {
    return 0;
}
