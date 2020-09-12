/*************************************************************************
	> File Name: 5.LeetCode1530.cpp
	> Author:赵睿 
	> Mail: 1767153298@qq.com
	> Created Time: 2020年09月12日 星期六 20时58分26秒
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
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

typedef pair<TreeNode *, int> PTI;

map<TreeNode *, int> dfs(TreeNode *root, int distance, int &ans) {
    map<TreeNode *, int> mp;
    if (!root) return mp;
    if (!root->left && !root->right) {
        mp.insert(PTI(root, 0));
        return mp;
    }
    auto left = dfs(root->left, distance, ans);
    auto right = dfs(root->right, distance, ans);
    for (auto &x : left) x.second++;
    for (auto &x : right) x.second++;
    for (auto &x : left) {
        for (auto &y : right) {
            if ((x.second + y.second) <= distance) ans++;
        }
    }
    for (auto &x : left) mp.insert(x);
    for (auto &x : right) mp.insert(x);
    return mp;
}

int countPairs(TreeNode *root, int distance) {
    int ans = 0;
    dfs(root, distance, ans);
    return ans;
}

int main() {
    return 0;
}
