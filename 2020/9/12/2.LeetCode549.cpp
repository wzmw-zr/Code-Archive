/*************************************************************************
	> File Name: 2.LeetCode549.cpp
	> Author:赵睿 
	> Mail: 1767153298@qq.com
	> Created Time: 2020年09月12日 星期六 16时18分16秒
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

typedef pair<int, int> PII;

pair<int, int> dfs(TreeNode *root, int &ans) {
    if (!root) return PII(0, 0);
    auto left = dfs(root->left, ans);
    auto right = dfs(root->right, ans);
    int l = 1, r = 1;
    if (root->left) {
        if ((root->val - 1) == root->left->val) {
            r = max(r, left.second + 1);
        } 
        if ((root->val + 1) == root->left->val) {
            l = max(l, left.first + 1);
        } 
    }
    if (root->right) {
        if ((root->val - 1) == root->right->val) {
            r = max(r, right.second + 1);
        } 
        if ((root->val + 1) == root->right->val) {
            l = max(l, right.first + 1);
        }
    }
    ans = max(ans, max(l, r));
    if (root->left && root->right) {
        if (((root->val - 1) == root->left->val) && ((root->val + 1) == root->right->val)) ans = max(ans, l + r - 1);
        if (((root->val + 1) == root->left->val) && ((root->val - 1) == root->right->val)) ans = max(ans, l + r - 1);     
    }
    return PII(l, r);
}

int longestConsecutive(TreeNode* root) {
    int ans = 0;
    dfs(root, ans);
    return ans;
}

int main() {
    return 0;
}
