/*************************************************************************
	> File Name: 1.LeetCode783.cpp
	> Author: 
	> Mail: 
	> Created Time: 2021年04月13日 星期二 00时01分58秒
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

void dfs(TreeNode *root, vector<int> &nums) {
    if (!root) return ;
    dfs(root->left, nums);
    nums.push_back(root->val);
    dfs(root->right, nums);
}

int minDiffInBST(TreeNode* root) {
    vector<int> nums;
    dfs(root, nums);
    int n = nums.size();
    int ans = INT32_MAX;
    for (int i = 0; i < n - 1; i++) ans = min(ans, nums[i + 1] - nums[i]);
    return ans;
}

int main() {
    return 0;
}
