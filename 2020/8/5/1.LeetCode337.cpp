/*************************************************************************
	> File Name: 1.LeetCode337.cpp
	> Author:赵睿 
	> Mail: 1767153298@qq.com
	> Created Time: 2020年08月05日 星期三 00时29分17秒
 ************************************************************************/

#include<iostream>
#include<string>
#include<vector>
#include<queue>
#include<stack>
#include<unordered_map>
#include<algorithm>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int val) : val(val), left(NULL), right(NULL) {}
};

typedef pair<TreeNode *, int> PTI;

unordered_map<TreeNode *, int> mp;

int rob(TreeNode* root) {
    if (!root) {
        mp[root] = 0;
        return 0;
    }
    if (root->left == NULL && root->right == NULL) {
        mp[root] = root->val;
        return root->val;
    }
    int left = rob(root->left);
    int right = rob(root->right);
    int mmax = left + right;
    mmax = max(mmax, root->val);
    if (root->left == NULL) {
        mmax = max(mmax, root->val + mp[root->right->left] + mp[root->right->right]);
    } else if (root->right == NULL) {
        mmax = max(mmax, root->val + mp[root->left->left] + mp[root->left->right]);
    } else {
        mmax = max(mmax, root->val + mp[root->right->left] + mp[root->right->right]);
        mmax = max(mmax, root->val + mp[root->left->left] + mp[root->left->right]);
    }
    mp[root] = mmax;
    return mmax;
}

int main() {
    return 0;
}
