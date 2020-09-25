/*************************************************************************
	> File Name: 1.LeetCode106.cpp
	> Author:赵睿 
	> Mail: 1767153298@qq.com
	> Created Time: 2020年09月25日 星期五 07时29分54秒
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

TreeNode *buildTree(vector<int> &inorder, vector<int> &postorder, int in_l, int in_r, int post_l, int post_r) {
    if (in_l == in_r) return new TreeNode(inorder[in_l]);
    if (in_l > in_r) return nullptr;
    TreeNode *ret = new TreeNode(postorder[post_r]);
    int i = in_l;
    for (i = in_l; i <= in_r; i++) {
        if (inorder[i] == postorder[post_r]) break;
    }
    ret->left = buildTree(inorder, postorder, in_l, i - 1, post_l, post_l + i - 1 - in_l);
    ret->right = buildTree(inorder, postorder, i + 1, in_r, post_l + i - in_l, post_r - 1);
    return ret;
}

TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
    return buildTree(inorder, postorder, 0, inorder.size() - 1, 0, postorder.size() - 1);
}

int main() {
    return 0;
}
