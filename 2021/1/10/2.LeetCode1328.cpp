/*************************************************************************
	> File Name: 2.LeetCode1328.cpp
	> Author: 
	> Mail: 
	> Created Time: 2021年01月10日 星期日 00时15分11秒
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

struct Node;

Node *NIL;

struct Node {
    int val;
    int height;
    Node *left;
    Node *right;
    Node() : val(0), height(0), left(this), right(this) {}
    Node(int val) : val(val), height(1), left(NIL), right(NIL) {}
};

void dfs(TreeNode *root, vector<int> &nums) {
    if (!root) return ;
    dfs(root->left, nums);
    nums.push_back(root->val);
    dfs(root->right, nums);
}

void update(Node *root) {
    if (root == NIL) return ;
    root->height = max(root->left->height, root->right->height) + 1;
}

Node *left_rotate(Node *root) {
    Node *temp = root->right;
    root->right = temp->left;
    temp->left = root;
    update(root);
    update(temp);
    return temp;
}

Node *right_rotate(Node *root) {
    Node *temp = root->left;
    root->left = temp->right;
    temp->right = root;
    update(root);
    update(temp);
    return temp;
}

Node *insert(Node *root, int val) {
    if (root == NIL) return new Node(val);
    if (root->val < val) root->right = insert(root->right, val); 
    else if (root->val > val) root->left = insert(root->right, val);
    else return root;
    if (abs(root->left->height - root->right->height) <= 1) {
        update(root);
        return root;
    }
    if (root->left->height > root->right->height) {
        if (root->left->left->height < root->left->right->height) root->left = left_rotate(root->left);
        root = right_rotate(root);
    } else {
        if (root->right->right->height < root->right->left->height) root->right = right_rotate(root->right);
        root = left_rotate(root);
    }
    update(root);
    return root;
}

TreeNode *duplicate_tree(Node *root) {
    if (root == NIL) return nullptr;
    TreeNode *temp = new TreeNode(root->val);
    temp->left = duplicate_tree(root->left);
    temp->right = duplicate_tree(root->right);
    return temp;
}

TreeNode* balanceBST(TreeNode* root) {
    vector<int> nums;
    dfs(root, nums);
    Node *temp = NIL;
    for (int &x : nums) temp = insert(temp, x);
    return duplicate_tree(temp);
}

int main() {
    return 0;
}
