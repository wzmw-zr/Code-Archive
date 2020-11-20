/*************************************************************************
	> File Name: 5.LeetCode1080.cpp
	> Author:赵睿 
	> Mail: 1767153298@qq.com
	> Created Time: 2020年11月20日 星期五 15时20分38秒
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
    TreeNode() = default;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

typedef pair<TreeNode *, int> PTI;

PTI dfs(TreeNode *root, int val, int limit) {
    if (!root) return PTI(nullptr, 0);
    if (!root->left && !root->right) {
        if (val + root->val < limit) return PTI(nullptr, 0);
        return PTI(root, 1);
    }
    PTI left = dfs(root->left, val + root->val, limit);
    PTI right = dfs(root->right, val + root->val, limit);
    root->left = left.first;
    root->right = right.first;
    if (!left.second && !right.second) return PTI(nullptr, 0);
    return PTI(root, 1);
}

TreeNode* sufficientSubset(TreeNode* root, int limit) {
    PTI ans = dfs(root, 0, limit);
    root = ans.first;
    return root;
}

int main() {
    return 0;
}
