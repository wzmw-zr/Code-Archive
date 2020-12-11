/*************************************************************************
	> File Name: 4.LeetCode1676.cpp
	> Author: 
	> Mail: 
	> Created Time: 2020年12月11日 星期五 18时56分58秒
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
    TreeNode(int val) : val(val), left(nullptr), right(nullptr) {}
};

int dfs(TreeNode *root, unordered_set<TreeNode *> &st, TreeNode * &ans, int &flag) {
    if (!root) return 0;
    int left = dfs(root->left, st, ans, flag);
    int right = dfs(root->right, st, ans, flag);
    if (st.count(root)) {
        if (left + right + 1 == st.size()) {
            if (!flag) {
                ans = root;
                flag = 1;
            }
        }
        return left + right + 1;
    }
    if (left + right == st.size()) {
        if (!flag) {
            ans = root;
            flag = 1;
        }
    }
    return left + right;
}

TreeNode* lowestCommonAncestor(TreeNode* root, vector<TreeNode*> &nodes) {
    unordered_set<TreeNode *> st;
    TreeNode *ans = nullptr;
    int flag = 0;
    for (auto &x : nodes) st.insert(x);
    dfs(root, st, ans, flag);
    return ans;
}

int main() {
    return 0;
}
