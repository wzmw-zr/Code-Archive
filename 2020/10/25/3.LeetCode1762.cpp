/*************************************************************************
	> File Name: 3.LeetCode1762.cpp
	> Author:赵睿 
	> Mail: 1767153298@qq.com
	> Created Time: 2020年10月25日 星期日 09时04分35秒
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

string serialize(TreeNode *root) {
    if (!root) return "";
    if (!root->left && !root->right) return to_string(root->val);
    return to_string(root->val) + "(" + serialize(root->left) + ")" + "(" + serialize(root->right) + ")";
}

string dfs(TreeNode *root, string &s_2, bool &ans) {
    if (!root) {
        if (s_2 == "") ans = true;
        return "";
    }
    if (!root->left && !root->right) {
        if (s_2 == to_string(root->val)) ans = true;
        return to_string(root->val);
    }
    string left = dfs(root->left, s_2, ans);
    string right = dfs(root->right, s_2, ans);
    if (s_2 == left || s_2 == right) ans = true;
    return to_string(root->val) + "(" + left + ")" + "(" + right + ")";
}

bool checkSubTree(TreeNode* t1, TreeNode* t2) {
    string s_2 = serialize(t2);
    bool ans = false;
    dfs(t1, s_2, ans);
    return ans;
}

int main() {
    return 0;
}
