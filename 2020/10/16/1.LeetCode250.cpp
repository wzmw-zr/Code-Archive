/*************************************************************************
	> File Name: 1.LeetCode250.cpp
	> Author:赵睿 
	> Mail: 1767153298@qq.com
	> Created Time: 2020年10月16日 星期五 08时05分13秒
 ************************************************************************/

#include<iostream>
#include<string>
#include<vector>
#include<queue>
#include<stack>
#include<map>
#include<set>
#include<algorithm>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int val) : val(val), left(nullptr), right(nullptr) {}
};

bool dfs(TreeNode *root, int &ans) {
    if (!root) return true;
    if (!root->left && !root->right) {
        ans++;
        return true;
    }
    bool left = dfs(root->left, ans);
    bool right = dfs(root->right, ans); 
    if (!root->left) {
        if (right && root->val == root->right->val) {
            ans++;
            return true;
        }
        return false;
    } 
    if (!root->right) {
        if (left && root->val == root->left->val) {
            ans++;
            return true;
        }
        return false;
    }
    if (left && right && root->val == root->left->val && root->val == root->right->val) {
        ans++;
        return true;
    }
    return false;
}

int countUnivalSubtrees(TreeNode* root) {
    int ans = 0;
    dfs(root, ans);
    return ans;
}

int main() {
    return 0;
}
