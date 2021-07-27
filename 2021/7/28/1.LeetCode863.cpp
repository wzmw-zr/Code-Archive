/*************************************************************************
	> File Name: 1.LeetCode863.cpp
	> Author: 
	> Mail: 
	> Created Time: 2021年07月28日 星期三 00时11分24秒
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
    TreeNode() = default;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

using PMB = pair<unordered_map<int, int>, bool>;

PMB dfs(TreeNode *root, TreeNode *target, int k, vector<int> &ans) {
    if (!root) return PMB(unordered_map<int, int>{}, false);
    PMB left = dfs(root->left, target, k, ans);
    PMB right = dfs(root->right, target, k, ans);
    unordered_map<int, int> mp;
    mp[root->val] = 1;
    for (auto &&[num, dis] : left.first) mp[num] = dis + 1;
    for (auto &&[num, dis] : right.first) mp[num] = dis + 1;
    if (root == target) {
        if (k == 0) ans.push_back(root->val);
        for (auto &&[num, dis] : left.first) {
            if (dis == k) ans.push_back(num);
        }
        for (auto &&[num, dis] : right.first) {
            if (dis == k) ans.push_back(num);
        }
        return PMB{mp, true};
    }
    if (left.second) {
        if (left.first[target->val] == k) ans.push_back(root->val);
        for (auto &&[num, dis] : right.first) {
            if (dis + left.first[target->val] == k) ans.push_back(num);
        }
        return PMB{mp, true};
    }
    if (right.second) {
        if (right.first[target->val] == k) ans.push_back(root->val);
        for (auto &&[num, dis] : left.first) {
            if (dis + right.first[target->val] == k) ans.push_back(num);
        }
        return PMB{mp, true};
    }
    return PMB{mp, false};
}

vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
    vector<int> ans;
    dfs(root, target, k, ans);
    return ans;
}

int main() {
    return 0;
}
