/*************************************************************************
	> File Name: 1.LeetCode776.cpp
	> Author:赵睿 
	> Mail: 1767153298@qq.com
	> Created Time: 2020年10月28日 星期三 06时49分53秒
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

void dfs(TreeNode *root, vector<TreeNode *> &nodes) {
    if (!root) return ;
    dfs(root->left, nodes);
    nodes.push_back(root);
    dfs(root->right, nodes);
}

TreeNode *b_s(vector<TreeNode *> &nodes, int V) {
    int l = 0, r = nodes.size() - 1, mid;
    while (l < r) {
        mid = (l + r + 1) >> 1;
        if (nodes[mid]->val == V) return nodes[mid];
        if (nodes[mid]->val < V) l = mid;
        else r = mid - 1;
    }
    return nodes[l];
}

TreeNode *split(TreeNode *root, TreeNode *temp, vector<TreeNode *> &ans) {
    if (!root) return nullptr;
    if (root == temp) {
        ans.push_back(temp);
        TreeNode *ans = temp->right;
        temp->right = nullptr;
        return ans;
    }
    if (root->val < temp->val) root->right = split(root->right, temp, ans);
    else root->left = split(root->left, temp, ans);
    return root;
}

vector<TreeNode*> splitBST(TreeNode* root, int V) {
    vector<TreeNode *> nodes, ans;
    dfs(root, nodes);
    if (nodes[0]->val > V || nodes[nodes.size() - 1]->val < V) {
        ans.push_back(nullptr);
        ans.push_back(root);
        return ans;
    } 
    TreeNode *temp = b_s(nodes, V);
    root = split(root, temp, ans);
    ans.push_back(root);
    return ans;
}

int main() {
    return 0;
}
