/*************************************************************************
	> File Name: 1.LeetCode437.cpp
	> Author: 
	> Mail: 
	> Created Time: 2021年09月28日 星期二 08时08分46秒
 ************************************************************************/

#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <stack>
#include <map>
#include <set>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int val) : val(val), left(nullptr), right(nullptr) {}
};

vector<long> dfs(TreeNode *root, int &ans, int &targetSum) {
    if (!root) return {};
    auto left = dfs(root->left, ans, targetSum);
    auto right = dfs(root->right, ans, targetSum);
    vector<long> ret;
    for (auto x : left) ret.push_back(x + root->val);
    for (auto x : right) ret.push_back(x + root->val);
    ret.push_back(root->val);
    for (int x : ret) {
        if (x == targetSum) ans++;
    }
    return ret;
}

int pathSum(TreeNode *root, int targetSum) {
    int ans = 0;
    dfs(root, ans, targetSum);
    return ans;
}

int main() {
    return 0;
}
