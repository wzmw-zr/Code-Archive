/*************************************************************************
	> File Name: 1.LeetCode671.cpp
	> Author: 
	> Mail: 
	> Created Time: 2021年07月27日 星期二 00时02分33秒
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

void dfs(TreeNode *root, set<int> &nums) {
    if (!root) return ;
    nums.insert(root->val);
    dfs(root->left, nums);
    dfs(root->right, nums);
}

int findSecondMinimumValue(TreeNode* root) {
    set<int> nums;
    dfs(root, nums);
    if (nums.size() < 2) return -1;
    return *next(nums.begin());
}

int main() {
    return 0;
}
