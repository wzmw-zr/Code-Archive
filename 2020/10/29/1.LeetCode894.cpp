/*************************************************************************
	> File Name: 1.LeetCode894.cpp
	> Author:赵睿 
	> Mail: 1767153298@qq.com
	> Created Time: 2020年10月29日 星期四 14时16分04秒
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

void erase_tree(TreeNode *root) {
    if (!root) return ;
    erase_tree(root->left);
    erase_tree(root->right);
    delete root;
}

TreeNode *copy_tree(TreeNode *root) {
    if (!root) return nullptr;
    TreeNode *ret = new TreeNode();
    ret->left = copy_tree(root->left);
    ret->right = copy_tree(root->right);
    return ret;
}

void dfs(TreeNode *Root, TreeNode *root, vector<TreeNode *> &ans, int N, int cnt) {
    if (N == cnt) {
        TreeNode *temp = copy_tree(Root);
        ans.push_back(temp);
        return ;
    }
    root->left = new TreeNode();
    root->right = new TreeNode();
    dfs(Root, root->left, ans, N, cnt + 2);
    dfs(Root, root->right, ans, N, cnt + 2);
    delete root->left;
    delete root->right;
    root->left = root->right = nullptr;
}

vector<TreeNode *> allPossibleFBT(int N) {
    vector<TreeNode *> ans;
    TreeNode *root = new TreeNode();
    dfs(root, root, ans, N, 1);
    erase_tree(root);
    return ans;
}
int main() {
    return 0;
}
