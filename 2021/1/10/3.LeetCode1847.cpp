/*************************************************************************
	> File Name: 3.LeetCode1847.cpp
	> Author: 
	> Mail: 
	> Created Time: 2021年01月10日 星期日 00时54分29秒
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

void dfs(vector<int> &nums, vector<int> &left, vector<int> &right, int ind_1, int ind_2, vector<vector<int>> &ans) {
    if (ind_1 == left.size() && ind_2 == right.size()) {
        ans.push_back(nums);
        return ;
    }
    if (ind_1 == left.size()) {
        auto temp = nums;
        for (int i = ind_2; i < right.size(); i++) temp.push_back(right[i]);
        ans.push_back(temp);
        return ;
    }
    if (ind_2 == right.size()) {
        auto temp = nums;
        for (int i = ind_1; i < left.size(); i++) temp.push_back(left[i]);
        ans.push_back(temp);
        return ;
    }
    nums.push_back(left[ind_1]);
    dfs(nums, left, right, ind_1 + 1, ind_2, ans);
    nums.pop_back();
    nums.push_back(right[ind_2]);
    dfs(nums, left, right, ind_1, ind_2 + 1, ans);
    nums.pop_back();
}

vector<vector<int>> BSTSequences(TreeNode* root) {
    if (!root) return vector<vector<int>>(1, vector<int>(0));
    if (!root->left && !root->right) return vector<vector<int>>(1, vector<int>({root->val}));
    vector<vector<int>> ans;
    auto left = BSTSequences(root->left);
    auto right = BSTSequences(root->right);
    vector<int> nums = {root->val};
    for (auto &x : left) {
        for (auto &y : right) {
            dfs(nums, x, y, 0, 0, ans);
        }
    }
    return ans;
}

int main() {
    return 0;
}
