/*************************************************************************
	> File Name: 2.LeetCode1609.cpp
	> Author:赵睿 
	> Mail: 1767153298@qq.com
	> Created Time: 2020年10月13日 星期二 15时46分39秒
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

void dfs(TreeNode *root, vector<vector<int>> &node, int level) {
    if (!root) return ;
    if (level == node.size()) node.push_back(vector<int>(0));
    node[level].push_back(root->val);
    dfs(root->left, node, level + 1);
    dfs(root->right, node, level + 1);
}

bool check_odd(vector<int> &node) {
    if (node[0] & 1) return false;
    for (int i = 1; i < node.size(); i++) {
        if (node[i] & 1) return false;
        if (node[i] >= node[i - 1]) return false;
    }
    return true;
}

bool check_even(vector<int> &node) {
    if (!(node[0] & 1)) return false;
    for (int i = 1; i < node.size(); i++) {
        if (!(node[i] & 1)) return false;
        if (node[i] <= node[i - 1]) return false;
    }
    return true;
}

bool isEvenOddTree(TreeNode* root) {
    vector<vector<int>> node;
    dfs(root, node, 0);
    for (int i = 0; i < node.size(); i++) {
        if (i & 1) {
            if (check_odd(node[i])) continue;
            return false;
        } else {
            if (check_even(node[i])) continue;
            return false;
        }
    }
    return true;
}

int main() {
    return 0;
}
