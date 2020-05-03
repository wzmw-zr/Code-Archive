/*************************************************************************
	> File Name: 1.LeetCode1477.cpp
	> Author:赵睿 
	> Mail: 1767153298@qq.com
	> Created Time: 2020年05月03日 星期日 09时06分04秒
 ************************************************************************/

#include<iostream>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left, *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {};
};

int GetHeight(TreeNode *root) {
    if (!root) return 0;
    int l = GetHeight(root->left);
    int r = GetHeight(root->right);
    if (l == -1 || r == -1) return -1;
    if (abs(l - r) > 1) return -1;
    return max(l, r) + 1;
}

bool isBalanced(TreeNode *root) {
    if (GetHeight(root) == -1) return false;
    return true;
}

int main() {
    return 0;
}
