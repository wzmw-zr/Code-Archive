/*************************************************************************
	> File Name: 3.LeetCode663.cpp
	> Author:赵睿 
	> Mail: 1767153298@qq.com
	> Created Time: 2020年10月13日 星期二 16时30分41秒
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

    TreeNode() : val(0), left(NULL), right(NULL) {}
    TreeNode(int val) : val(val), left(NULL), right(NULL) {}
};

int getSum(TreeNode *root) {
    if (!root) return 0;
    if (!root->left && !root->right) return root->val;
    return root->val + getSum(root->left) + getSum(root->right);
}

int checkEqualTree(TreeNode *root, int &sum, bool &ans) {
    if (!root) return 0;
    if (!root->left && !root->right) return root->val;
    int left = checkEqualTree(root->left, sum, ans);
    if (left * 2 == sum) ans = true;
    int right = checkEqualTree(root->right, sum, ans);
    if (right * 2 == sum) ans = true;
    return root->val + left + right;
}

bool checkEqualTree(TreeNode* root) {
    int sum = getSum(root);
    bool ans = false;
    checkEqualTree(root, sum, ans);
    return ans;
}

int main() {
    return 0;
}
