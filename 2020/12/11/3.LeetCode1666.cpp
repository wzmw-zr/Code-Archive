/*************************************************************************
	> File Name: 3.LeetCode1666.cpp
	> Author: 
	> Mail: 
	> Created Time: 2020年12月11日 星期五 09时40分49秒
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

struct Node {
    int val;
    Node *left;
    Node *right;
    Node *parent;
};

void dfs(Node *root, Node *leaf, vector<Node *> &path_t, vector<Node *> &path) {
    if (!root) return ;
    path_t.push_back(root);
    if (root == leaf) {
        path = path_t;
        path_t.pop_back();
        return ;
    }
    dfs(root->left, leaf, path_t, path);
    dfs(root->right, leaf, path_t, path);
    path_t.pop_back();
}

Node* flipBinaryTree(Node* root, Node * leaf) {
    vector<Node *> path, path_t;
    dfs(root, leaf, path_t, path);
    int n = path.size();
    for (int i = 1; i < n; i++) {
        if (path[i]->left && path[i]->left != path[i + 1]) {
            path[i]->right = path[i]->left;
            path[i]->left = nullptr;
        }
        path[i]->left = path[i - 1];
    }
    if (path[0]->left && path[0]->left == path[1]) path[0]->left = nullptr;
    if (path[0]->right && path[0]->right == path[1]) path[0]->right = nullptr;
    for (int i = 0; i < n - 1; i++) path[i]->parent = path[i + 1];
    path[n - 1]->parent = nullptr;
    return path[n - 1];
}

int main() {
    return 0;
}
