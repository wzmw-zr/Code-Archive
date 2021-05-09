/*************************************************************************
	> File Name: 1.LeetCode872.cpp
	> Author: 
	> Mail: 
	> Created Time: 2021年05月10日 星期一 00时03分47秒
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

void dfs(TreeNode *root, vector<int> &leaves) {
    if (!root) return ;
    if (!root->left && !root->right) {
        leaves.push_back(root->val);
        return ;
    }
    dfs(root->left, leaves);
    dfs(root->right, leaves);
}

bool leafSimilar(TreeNode* root1, TreeNode* root2) {
    vector<int> leaves1, leaves2;
    dfs(root1, leaves1);
    dfs(root2, leaves2);
    int n = leaves1.size(), m = leaves2.size();
    if (n != m) return false;
    for (int i = 0; i < n; i++) 
        if (leaves1[i] != leaves2[i]) return false;
    return true;
}

int main() {
    return 0;
}
