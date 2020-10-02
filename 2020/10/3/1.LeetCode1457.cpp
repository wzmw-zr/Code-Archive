/*************************************************************************
	> File Name: 1.LeetCode1457.cpp
	> Author:赵睿 
	> Mail: 1767153298@qq.com
	> Created Time: 2020年10月03日 星期六 07时11分27秒
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

bool check(vector<int> &path) {
    map<int, int> mp;
    int cnt = 0;
    for (auto &x : path) mp[x]++;
    for (auto &x : mp) {
        if (x.second & 1) cnt++;
    }
    if (cnt == 0 || cnt == 1) return true;
    return false;
}

void dfs(TreeNode *root, vector<int> &path, int &ans) {
    if (!root) return ;
    if (!root->left && !root->right) {
        path.push_back(root->val);
        if (check(path)) ans++;
        path.pop_back();
        return ;
    }
    path.push_back(root->val);
    dfs(root->left, path, ans);
    dfs(root->right, path, ans);
    path.pop_back();
}

int pseudoPalindromicPaths (TreeNode* root) {
    vector<int> path;
    int ans = 0;
    dfs(root, path, ans);
    return ans;
}

int main() {
    return 0;
}
