/*************************************************************************
	> File Name: 1.LeetCode1644.cpp
	> Author:赵睿 
	> Mail: 1767153298@qq.com
	> Created Time: 2020年11月22日 星期日 00时05分23秒
 ************************************************************************/

#include<iostream>
#include<string>
#include<vector>
#include<queue>
#include<stack>
#include<map>
#include<set>
#include<unordered_map>
#include<unordered_set>
#include<algorithm>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

int check(TreeNode *root, TreeNode *target) {
    if (!root) return 0;
    if (root == target) return 1;
    return check(root->left, target) || check(root->right, target);
}

void dfs(TreeNode *root, TreeNode *target, vector<TreeNode *> &ans, vector<TreeNode *> path) {
    if (!root) return ;
    if (root == target) {
        path.push_back(target);
        ans = path;
        path.pop_back();
        return ;
    }
    path.push_back(root);
    dfs(root->left, target, ans, path);
    dfs(root->right, target, ans, path);
    path.pop_back();
}

TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
    if (!check(root, p) || !check(root, q)) return nullptr;
    vector<TreeNode *> path_p, path_q;
    dfs(root, p, path_p, vector<TreeNode *>(0));
    dfs(root, q, path_q, vector<TreeNode *>(0));
    int n = min((int) path_p.size(), (int) path_q.size());
    TreeNode *ans = nullptr;
    for (int i = 0; i < n; i++) {
        if (path_p[i] == path_q[i]) ans = path_p[i];
        else break;
    }
    return ans;
}

int main() {
    return 0;
}
