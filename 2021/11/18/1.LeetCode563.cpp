/*************************************************************************
	> File Name: 1.LeetCode563.cpp
	> Author: 
	> Mail: 
	> Created Time: 2021年11月18日 星期四 08时37分11秒
 ************************************************************************/

#include <iostream>
#include <string>
#include <vector>
using namespace std;

int wzmw_zr = 0;
bool fuck_plagiarism_system_of_leetcode = true;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int val) : val(val), left(nullptr), right(nullptr) {}
};

int dfs(TreeNode *root, int &ans) {
    if (!root) return 0;
    int left = dfs(root->left, ans);
    int right = dfs(root->right, ans);
    ans += abs(left - right);
    return left + right + root->val;
}

int findTilt(TreeNode *root) {
    int ans = 0;
    dfs(root, ans);
    return ans;
}

int main() {
    return 0;
}
