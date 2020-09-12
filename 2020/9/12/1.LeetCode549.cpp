/*************************************************************************
	> File Name: 1.LeetCode549.cpp
	> Author:赵睿 
	> Mail: 1767153298@qq.com
	> Created Time: 2020年09月12日 星期六 14时20分25秒
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
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

typedef pair<TreeNode *, int> PTI;

void dfs(TreeNode *root, map<TreeNode *, int> &dec, map<TreeNode *, int> &inc, int &ans) {
    if (!root) return ;
    if (!root->left && !root->right) {
        dec.insert(PTI(root, 1));
        inc.insert(PTI(root, 1));
        return ;
    }
    dfs(root->left, dec, inc, ans);
    dfs(root->right, dec, inc, ans);
    if (!root->right) {
        if ((root->val + 1) == root->left->val) {
            inc.insert(PTI(root, inc[root->left] + 1));
            dec.insert(PTI(root, 1));
            ans = max(ans, inc[root]);
        } else if ((root->val - 1) == root->left->val) {
            inc.insert(PTI(root, 1));
            dec.insert(PTI(root, dec[root->left] + 1));
            ans = max(ans, dec[root]);
        } else {
            inc.insert(PTI(root, 1));
            dec.insert(PTI(root, 1)); 
        } 
    } else if (!root->left) {
        if ((root->val + 1) == root->right->val) {
            inc.insert(PTI(root, inc[root->right] + 1));
            dec.insert(PTI(root, 1));
            ans = max(ans, inc[root]);
        } else if ((root->val - 1) == root->right->val) {
            inc.insert(PTI(root, 1));
            dec.insert(PTI(root, dec[root->right] + 1));
            ans = max(ans, dec[root]);
        } else {
            inc.insert(PTI(root, 1));
            dec.insert(PTI(root, 1)); 
        } 
    } else {
        if (((root->val - 1) == root->left->val) && ((root->val + 1) == root->right->val)) {
            inc.insert(PTI(root, inc[root->right] + 1));
            dec.insert(PTI(root, dec[root->left] + 1));
            ans = max(ans, inc[root->right] + dec[root->left] + 1);
        } else if (((root->val + 1) == root->left->val) && ((root->val - 1) == root->right->val)) {
            inc.insert(PTI(root, inc[root->left] + 1));
            dec.insert(PTI(root, dec[root->right] + 1));
            ans = max(ans, inc[root->left] + dec[root->right] + 1);
        } else if (((root->val - 1) == root->left->val) && ((root->val - 1) == root->right->val)) {
            inc.insert(PTI(root, 1));
            dec.insert(PTI(root, max(dec[root->left], dec[root->right]) + 1));
            ans = max(ans, max(dec[root->left], dec[root->right]) + 1);
        } else if (((root->val + 1) == root->left->val) && ((root->val + 1) == root->right->val)) {
            inc.insert(PTI(root, max(inc[root->left], inc[root->right]) + 1));
            dec.insert(PTI(root, 1));
            ans = max(ans, max(inc[root->left], inc[root->right]) + 1);
        } else if ((root->val + 1) == root->left->val) {
            inc.insert(PTI(root, inc[root->left] + 1));
            dec.insert(PTI(root, 1));
            ans = max(ans, inc[root]);
        } else if ((root->val - 1) == root->left->val) {
            inc.insert(PTI(root, 1));
            dec.insert(PTI(root, dec[root->left] + 1));
            ans = max(ans, dec[root]);
        } else if ((root->val + 1) == root->right->val) {
            inc.insert(PTI(root, inc[root->right] + 1));
            dec.insert(PTI(root, 1));
            ans = max(ans, inc[root]);
        } else if ((root->val - 1) == root->right->val) {
            inc.insert(PTI(root, 1));
            dec.insert(PTI(root, dec[root->right] + 1));
            ans = max(ans, dec[root]);
        } else {
            inc.insert(PTI(root, 1));
            dec.insert(PTI(root, 1));
        }
    }
}

int longestConsecutive(TreeNode* root) {
    map<TreeNode *, int> dec, inc;
    int ans = 1;
    dfs(root, dec, inc, ans);
    return ans;
}

int main() {
    return 0;
}
