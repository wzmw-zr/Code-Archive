/*************************************************************************
	> File Name: 1.LeetCode99.cpp
	> Author:赵睿 
	> Mail: 1767153298@qq.com
	> Created Time: 2020年08月08日 星期六 00时27分13秒
 ************************************************************************/

#include<iostream>
#include<string>
#include<vector>
#include<queue>
#include<stack>
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

void build(TreeNode *root, vector<TreeNode *> &order) {
    if (!root) return ;
    build(root->left, order);
    order.push_back(root);
    build(root->right, order);
}

void recoverTree(TreeNode* root) {
    vector<TreeNode *> order;
    build(root, order);
    TreeNode *node_1 = nullptr, *node_2 = nullptr;
    for (int i = 0; i < order.size() - 1; i++) {
        if (order[i]->val < order[i + 1]->val) continue;
        node_1 = order[i];
        for (int j = i + 2; j < order.size(); j++) {
            if (order[j]->val > order[j - 1]->val) continue;
            node_2 = order[j];
            break;
        }
        if (node_2 == nullptr) node_2 = order[i + 1];
    }
    int tmp = node_1->val;
    node_1->val = node_2->val;
    node_2->val = tmp;
}

int main() {
    return 0;
}
