/*************************************************************************
	> File Name: 1.LeetCode993.cpp
	> Author: 
	> Mail: 
	> Created Time: 2021年05月17日 星期一 00时05分33秒
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

void get_level(TreeNode *root, int x, int level, int &ans) {
    if (!root) return ;
    if (root->val == x) {
        ans = level;
        return ;
    }
    get_level(root->left, x, level + 1, ans);
    get_level(root->right, x, level + 1, ans);
}

int get_father(TreeNode *root, int x) {
    if (!root) return -1;
    if (root->left && (root->left->val == x)) return root->val;
    if (root->right && (root->right->val == x)) return root->val;
    if (root->val == x) return -1;
    int left = get_father(root->left, x);
    int right = get_father(root->right, x);
    return max(left, right);
}


bool isCousins(TreeNode* root, int x, int y) {
    int level_x, level_y;
    get_level(root, x, 0, level_x);
    get_level(root, y, 0, level_y);
    if (level_x != level_y) return false;
    int fa_x = get_father(root, x);
    int fa_y = get_father(root, y);
    return fa_x != fa_y;
}

int main() {
    return 0;
}
