/*************************************************************************
	> File Name: 6.LeetCode5937.cpp
	> Author: 
	> Mail: 
	> Created Time: 2021年12月11日 星期六 23时11分06秒
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

//Not Complete
int wzmw_zr = 0;
bool fuck_plagiarism_system_of_leetcode = true;

using PIS = pair<int, string>;

struct My_TreeNode {
    PIS val;
    My_TreeNode *left;
    My_TreeNode *right;
    int size;
    int height;

    My_TreeNode() = default;
    My_TreeNode(PIS val) : val(val), left(this), right(this), size(0), height(0) {}
    My_TreeNode(PIS val, My_TreeNode *left, My_TreeNode *right) : val(val), left(left), right(right), size(1), height(1) {}
};

My_TreeNode *LEAF = new My_TreeNode(PIS(0, ""));

struct Tree {
    My_TreeNode *_root;
    
    Tree() : _root(LEAF) {}

    void update(My_TreeNode *root) {
        if (root == LEAF) return ;
        root->size = root->left->size + root->right->size + 1;
        root->height = max(root->left->height, root->right->height) + 1;
    }

    My_TreeNode *left_rotate(My_TreeNode *root) {
        if (root == LEAF) return root;
        My_TreeNode *right = root->right;
        root->right = right->left;
        right->left = root;
        update(root);
        update(right);
        return right;
    }

    My_TreeNode *right_rotate(My_TreeNode *root) {
        if (root == LEAF) return root;
        My_TreeNode *left = root->left;
        root->left = left->right;
        left->right = root;
        update(root);
        update(left);
        return left;
    }

    My_TreeNode *maintain(My_TreeNode *root) {
        if (root == LEAF) return root;
        if (abs(root->left->height - root->right->height) <= 1) return root;
        if (root->left->height > root->right->height) {
            if (root->left->left->height < root->left->right->height) root->left = left_rotate(root->left);
            root = right_rotate(root);
        } else {
            if (root->right->left->height > root->right->right->height) root->right = right_rotate(root->right);
            root = left_rotate(root);
        }
        return root;
    }

    void insert(PIS val) {
        _root = insert(_root, val);
    }

    string find_k_th_element(int k) {
        return find_k_th_element(_root, k);
    }

    My_TreeNode *insert(My_TreeNode *root, PIS &val) {
        if (root == LEAF) return new My_TreeNode(val, LEAF, LEAF);
        if (root->val == val) return root;
        if (root->val < val) root->right = insert(root->right, val);
        else root->left = insert(root->left, val);
        update(root);
        root = maintain(root);
        return root;
    }
    
    string find_k_th_element(My_TreeNode *root, int k) {
        if (root == LEAF) return "";
        if (root->left->size + 1 == k) return root->val.second;
        if (root->left->size + 1 < k) return find_k_th_element(root->right, k - root->left->size - 1);
        return find_k_th_element(root->left, k);
    }

    void print(My_TreeNode *root, int level) {
        if (root == LEAF) return ;
        cout << "level = " << level << ", (" << root->val.first << ", " << root->val.second << ")" << endl;
        print(root->left, level + 1);
        print(root->right, level + 1);
    }

    void print() {
        int level = 1;
        print(_root, level);
    }
};


class SORTracker {
public:
    Tree tree;
    int ind = 1;

    SORTracker() : tree(Tree()) {}

    void add(string name, int score) {
        PIS val(score, name);
        tree.insert(val);
        tree.print();
    }

    string get() {
        string ans = tree.find_k_th_element(ind);
        ind++;
        return ans;
    }
};

int main() {
    return 0;
}
