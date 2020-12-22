/*************************************************************************
	> File Name: 1.LeetCode103.cpp
	> Author: 
	> Mail: 
	> Created Time: 2020年12月22日 星期二 07时58分06秒
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
    TreeNode() = default;
    TreeNode(int val) : val(val), left(nullptr), right(nullptr) {}
};

void dfs(TreeNode *root, vector<vector<int>> &ans, int level) {
    if (!root) return ;
    if (ans.size() == level) ans.push_back(vector<int>(0));
    ans[level].push_back(root->val);
    dfs(root->left, ans, level + 1);
    dfs(root->right, ans, level + 1);
}

vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
    vector<vector<int>> ans;
    dfs(root, ans, 0);
    int n = ans.size();
    for (int i = 0; i < n; i++) {
        if (i & 1) reverse(ans[i].begin(), ans[i].end());
    }
    return ans;
}

int main() {
    return 0;
}
