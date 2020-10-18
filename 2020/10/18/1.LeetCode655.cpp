/*************************************************************************
	> File Name: 1.LeetCode655.cpp
	> Author:赵睿 
	> Mail: 1767153298@qq.com
	> Created Time: 2020年10月18日 星期日 07时39分43秒
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
    TreeNode() = default;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

int getWidth(TreeNode *root) {
    if (!root) return 0;
    if (!root->left && !root->right) return 1;
    int left = getWidth(root->left), right = getWidth(root->right);
    return 2 * max(left, right) + 1;
}

int getHeight(TreeNode *root) {
    if (!root) return 0;
    if (!root->left && !root->right) return 1;
    int left = getHeight(root->left), right = getHeight(root->right);
    return max(left, right) + 1;
}

void dfs(TreeNode *root, vector<vector<string>> &ans, int level, int left, int right) {
    if (!root) return ;
    if (left > right) return ;
    int mid = (left + right) / 2;
    ans[level][mid] = to_string(root->val);
    dfs(root->left, ans, level + 1, left, mid - 1);
    dfs(root->right, ans, level + 1, mid + 1, right);
}

vector<vector<string>> printTree(TreeNode* root) {
    int width = getWidth(root), height = getHeight(root);
    vector<vector<string>> ans(height, vector<string>(width, ""));
    dfs(root, ans, 0, 0, width - 1);
    return ans;
}

int main() {
    return 0;
}
