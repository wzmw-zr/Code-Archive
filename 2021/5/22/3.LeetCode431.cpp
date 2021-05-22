/*************************************************************************
	> File Name: 3.LeetCode431.cpp
	> Author: 
	> Mail: 
	> Created Time: 2021年05月22日 星期六 22时11分53秒
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
    vector<Node *> children;

    Node() {}
    Node(int val) : val(val) {}
    Node(int val, vector<Node *> children) : val(val), children(children) {}
};

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int val) : val(val), left(nullptr), right(nullptr) {}
};


class Codec {
public:
    // Encodes an n-ary tree to a binary tree.
    TreeNode* encode(Node* root) {
        if (!root) return nullptr;
        TreeNode *_root = new TreeNode(root->val);
        int n = root->children.size();
        if (n == 0) return _root;
        vector<TreeNode *> nodes(n, nullptr);
        for (int i = 0; i < n; i++) {
            nodes[i] = encode(root->children[i]);
            if (i) nodes[i - 1]->right = nodes[i];
        }
        _root->left = nodes[0];
        return _root;
    }

    // Decodes your binary tree to an n-ary tree.
    Node* decode(TreeNode* root) {
        if (!root) return nullptr;
        vector<Node *> nodes;
        TreeNode *node = root->left;
        while (node) {
            nodes.push_back(decode(node));
            node = node->right;
        }
        Node *_root = new Node(root->val, nodes);
        return _root;
    }
};

int main() {
    return 0;
}
