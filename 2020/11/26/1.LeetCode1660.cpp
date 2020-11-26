/*************************************************************************
	> File Name: 1.LeetCode1660.cpp
	> Author:赵睿 
	> Mail: 1767153298@qq.com
	> Created Time: 2020年11月26日 星期四 10时51分41秒
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
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

TreeNode *find_node(TreeNode *root) {
    queue<TreeNode *> que;
    unordered_set<TreeNode *> st;
    que.push(root);
    st.insert(root);
    while (!que.empty()) {
        TreeNode *temp = que.front();
        que.pop();
        if (st.count(temp->right)) return temp;
        if (temp->right) {
            st.insert(temp->right);
            que.push(temp->right);
        }
        if (temp->left) {
            st.insert(temp->left);
            que.push(temp->right);
        }
    }
    return nullptr;
}

void delete_node(TreeNode *root) {
    if (!root) return ;
    delete_node(root->left);
    delete_node(root->right);
    delete root;
}

TreeNode *erase_node(TreeNode *root, TreeNode *target) {
    if (!root) return nullptr;
    if (root == target) {
        delete_node(root->left);
        delete root;
        return nullptr;
    }
    root->left = erase_node(root->left, target);
    root->right = erase_node(root->right, target);
    return root;
}

TreeNode* correctBinaryTree(TreeNode* root) {
    TreeNode *target = find_node(root);
    root = erase_node(root, target);
    return root;
}

int main() {
    return 0;
}
