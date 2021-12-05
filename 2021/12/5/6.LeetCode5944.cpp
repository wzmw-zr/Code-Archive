/*************************************************************************
	> File Name: 6.LeetCode5944.cpp
	> Author: 
	> Mail: 
	> Created Time: 2021年12月05日 星期日 14时00分59秒
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

struct Node {
    int val;
    Node *parent;
    Node *left;
    Node *right;

    Node() : val(0), parent(nullptr), left(nullptr), right(nullptr) {}
    Node(int val) : val(val), parent(nullptr), left(nullptr), right(nullptr) {}
};

int wzmw_zr = 0;
bool fuck_plagiarism_system_of_leetcode = true;

Node *rebuild(TreeNode *root) {
    if (!root) return nullptr;
    Node *_root = new Node(root->val);
    _root->left = rebuild(root->left);
    _root->right = rebuild(root->right);
    if (_root->left) _root->left->parent = _root;
    if (_root->right) _root->right->parent = _root;
    return _root;
}

Node *find_node(Node *root, int val) {
    if (!root) return nullptr;
    if (root->val == val) return root;
    Node *left = find_node(root->left, val);
    if (left) return left;
    Node *right = find_node(root->right, val);
    return right;
}

string generate_path(Node *root, Node *start) {
    vector<Node *> nodes;
    while (start != root) {
        nodes.push_back(start);
        start = start->parent;
    }
    string path = "";
    int n = nodes.size();
    for (int i = n - 1; i >= 0; i--) {
        if (nodes[i] == root->left) {
            path += "L";
            root = root->left;
        } else {
            path += "R";
            root = root->right;
        }
    }
    return path;
}

string getDirections(TreeNode* root, int startValue, int destValue) {
    Node *_root = rebuild(root);
    Node *start = find_node(_root, startValue);
    Node *dest = find_node(_root, destValue);
    string start_path = generate_path(_root, start);
    string dest_path = generate_path(_root, dest);
    int m = start_path.size(), n = dest_path.size();
    int common = 0;
    while (start_path[common] && dest_path[common] && start_path[common] == dest_path[common]) common++;
    string ans = string(m - common, 'U') + dest_path.substr(common);
    return ans;
}

int main() {
    return 0;
}
