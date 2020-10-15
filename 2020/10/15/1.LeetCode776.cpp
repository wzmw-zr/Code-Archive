/*************************************************************************
	> File Name: 1.LeetCode776.cpp
	> Author:赵睿 
	> Mail: 1767153298@qq.com
	> Created Time: 2020年10月15日 星期四 07时42分55秒
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
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

int dfs(TreeNode *root, TreeNode *&node_1, int V) {
    if (!root) return INT32_MIN;
    if (!root->left && !root->right) return root->val;
    int left = dfs(root->left, node_1, V);
    int right = dfs(root->right, node_1, V);
    int mmax = max(root->val, max(left, right));
    if (mmax <= V) node_1 = root;
    return mmax;
}

void handle(TreeNode *root, TreeNode *node_1) {
    if (!root) return ;
    if (root->left && root->left == node_1) {
        root->left = NULL; 
        return ;
    }
    if (root->right && root->right == node_1) {
        root->right = NULL; 
        return ;
    }
    handle(root->left, node_1);
    handle(root->right, node_1);
}

vector<TreeNode*> splitBST(TreeNode* root, int V) {
    vector<TreeNode *> ans;
    TreeNode *node_1 = NULL;
    dfs(root, node_1, V);
    if (node_1 == root) {
        ans.push_back(root);
        ans.push_back(NULL);
    } else {
        ans.push_back(root);
        ans.push_back(node_1);
        handle(root, node_1);
    }
    return ans;
}

int main() {
    return 0;
}
