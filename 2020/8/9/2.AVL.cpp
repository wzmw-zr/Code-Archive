/*************************************************************************
	> File Name: 2.AVL.cpp
	> Author:赵睿 
	> Mail: 1767153298@qq.com
	> Created Time: 2020年08月09日 星期日 17时58分41秒
 ************************************************************************/

#include<iostream>
#include<ctime>
using namespace std;

struct TreeNode {
    int val;
    int height;
    TreeNode *left;
    TreeNode *right;
    
    TreeNode();
    TreeNode(int val);
};

struct Tree {
    TreeNode *__root;
    static TreeNode __NIL;
    static TreeNode *NIL;

    Tree();

    void insert(int val);
    TreeNode *__insert(TreeNode *root, int val);
    void erase(int val);
    TreeNode *__erase(TreeNode *root, int val);
    TreeNode *update(TreeNode *root);
    TreeNode *left_rotate(TreeNode *root);
    TreeNode *right_rotate(TreeNode *root);
    TreeNode *predecessor(TreeNode *root);
    TreeNode *keep_balance(TreeNode *root);

    void inorder();
    void __inorder(TreeNode *root);
};

TreeNode Tree::__NIL;
TreeNode *Tree::NIL = &(Tree::__NIL);

TreeNode::TreeNode()
: height(0)
, left(this)
, right(this) {}

TreeNode::TreeNode(int val) 
: val(val)
, height(1)
, left(Tree::NIL)
, right(Tree::NIL) {}

Tree::Tree()
: __root(this->NIL) {
    NIL->height = 0;
    NIL->left = NIL;
    NIL->right = NIL;
}

void Tree::insert(int val) {
    this->__root = this->__insert(this->__root, val);
}

TreeNode *Tree::update(TreeNode *root) {
    root->height = max(root->left->height, root->right->height) + 1;
    return root;
}

TreeNode *Tree::left_rotate(TreeNode *root) {
    TreeNode *temp = root->right;
    root->right = temp->left;
    temp->left = root;
    root = update(root);
    return update(temp);
}

TreeNode *Tree::right_rotate(TreeNode *root) {
    TreeNode *temp = root->left;
    root->left = temp->right;
    temp->right = root;
    root = update(root);
    return update(temp);
}

TreeNode *Tree::keep_balance(TreeNode *root) {
    if (root == NIL) return root;
    int l_h = root->left->height;
    int r_h = root->right->height;
    if (abs(l_h - r_h) <= 1) return update(root);
    if (l_h > r_h) {
        if (root->left->left->height < root->left->right->height) 
            root->left = left_rotate(root->left);
        root = right_rotate(root);
    } else {
        if (root->right->right->height < root->right->left->height) 
            root->left = right_rotate(root->left);
        root = left_rotate(root);
    }
    return update(root);
}

TreeNode *Tree::__insert(TreeNode *root, int val) {
    if (root == NIL) return new TreeNode(val);
    if (root->val == val) return root;
    if (root->val < val) root->right = __insert(root->right, val);
    else root->left = __insert(root->left, val);
    return keep_balance(root);
}

void Tree::erase(int val) {
    this->__root = this->__erase(this->__root, val);
}

TreeNode *Tree::predecessor(TreeNode *root) {
    TreeNode *temp = root->left;
    while (temp->right != NIL) temp = temp->right;
    return temp;
}

TreeNode *Tree::__erase(TreeNode *root, int val) {
    if (root == NIL) return root;
    if (root->val < val) root->right = __erase(root->right, val);
    else if (root->val > val) root->left = __erase(root->left, val);
    else {
        if ((root->left == NIL) || (root->right == NIL)) {
            TreeNode *temp = (root->left == NIL) ? root->right : root->left;
            delete root;
            return temp;
        }
        TreeNode *temp = predecessor(root);
        root->val = temp->val;
        root->left = __erase(root->left, temp->val);
    }
    return keep_balance(root);
}

void Tree::inorder() {
    __inorder(__root);
    cout << endl;
}

void Tree::__inorder(TreeNode *root) {
    if (root == NIL) return ;
    __inorder(root->left);
    cout << root->val << " ";
    __inorder(root->right);
}


int main() {
    srand(time(0));
    Tree tree;
    for (int i = 1; i <= 20; i++) {
        int temp = rand() % 10000;
        tree.insert(temp);
        tree.inorder();
    }
    return 0;
}
