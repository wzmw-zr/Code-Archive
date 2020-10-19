/*************************************************************************
	> File Name: 1.LeetCode652.cpp
	> Author:赵睿 
	> Mail: 1767153298@qq.com
	> Created Time: 2020年10月19日 星期一 09时14分53秒
 ************************************************************************/

#include<iostream>
#include<string>
#include<vector>
#include<queue>
#include<stack>
#include<unordered_map>
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

void dfs(TreeNode *root, unordered_map<string, TreeNode *> &mp, unordered_map<TreeNode *, int> &ans) {
    if (!root) return ;
    string s = serialize(root);
    if (mp.find(s) == mp.end()) mp[s] = root;
    else ans[mp[s]] = 1;
    dfs(root->left, mp, ans);
    dfs(root->right, mp, ans);
}

vector<TreeNode*> findDuplicateSubtrees(TreeNode* root) {
    unordered_map<string, TreeNode *> mp;
    unordered_map<TreeNode *, int> ans;
    vector<TreeNode *> res;
    dfs(root, mp, ans);
    for (auto &x : ans) res.push_back(x.first);
    return res;
}

int main() {
    return 0;
}
