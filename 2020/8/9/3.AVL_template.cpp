/*************************************************************************
	> File Name: 3.AVL_template.cpp
	> Author:赵睿 
	> Mail: 1767153298@qq.com
	> Created Time: 2020年08月09日 星期日 18时37分22秒
 ************************************************************************/

#include<iostream>
#include<string>
#include<ctime>
using namespace std;

template<typename ValueType>
class TreeNode {
public:
    ValueType __val;
    int height;
    TreeNode *left;
    TreeNode *right;

    TreeNode();
    TreeNode(ValueType val);
    ~TreeNode();
};

template<typename ValueType>
class AVLTree {
public:
    typedef TreeNode<ValueType> NodeType;
    NodeType *__root;
    static NodeType __NIL;
    static NodeType *NIL;

    AVLTree();
    ~AVLTree();
    void delete_tree(NodeType *root);
    void insert(ValueType val);
    NodeType *__insert(NodeType *root, ValueType val);
    void erase(ValueType val);
    NodeType *__erase(NodeType *root, ValueType val);
    NodeType *left_rotate(NodeType *root);
    NodeType *right_rotate(NodeType *root);
    NodeType *predecessor(NodeType *root);
    NodeType *update(NodeType *root);
    NodeType *keep_balance(NodeType *root);
    void inorder();
    void __inorder(NodeType *root);
};

template<typename ValueType>
TreeNode<ValueType> AVLTree<ValueType>::__NIL;

template<typename ValueType>
TreeNode<ValueType> *AVLTree<ValueType>::NIL = &(AVLTree<ValueType>::__NIL);

template<typename ValueType>
TreeNode<ValueType>::TreeNode()
: height(0) 
, left(this)
, right(this) {}

template<typename ValueType>
TreeNode<ValueType>::TreeNode(ValueType val) 
: __val(val)
, height(1)
, left(AVLTree<ValueType>::NIL)
, right(AVLTree<ValueType>::NIL) {}

template<typename ValueType>
TreeNode<ValueType>::~TreeNode() {}


template<typename ValueType>
AVLTree<ValueType>::AVLTree() 
: __root(this->NIL) {}

template<typename ValueType>
AVLTree<ValueType>::~AVLTree() {
    delete_tree(this->__root);
}

template<typename ValueType>
void AVLTree<ValueType>::delete_tree(TreeNode<ValueType> *root) {
    if (root == NIL) return ;
    delete_tree(root->left);
    delete_tree(root->right); 
    delete root;
}

template<typename ValueType>
void AVLTree<ValueType>::insert(ValueType val) {
    this->__root = this->__insert(this->__root, val);
}

template<typename ValueType>
TreeNode<ValueType> *AVLTree<ValueType>::update(TreeNode<ValueType> *root) {
    root->height = max(root->left->height, root->right->height) + 1;
    return root;
}

template<typename ValueType>
TreeNode<ValueType> *AVLTree<ValueType>::left_rotate(TreeNode<ValueType> *root) {
    TreeNode<ValueType> *temp = root->right;
    root->right = temp->left;
    temp->left = root;
    root = update(root);
    return update(temp);
}

template<typename ValueType>
TreeNode<ValueType> *AVLTree<ValueType>::right_rotate(TreeNode<ValueType> *root) {
    TreeNode<ValueType> *temp = root->left;
    root->left = temp->right;
    temp->right = root;
    root = update(root);
    return update(temp);
}

template<typename ValueType>
TreeNode<ValueType> *AVLTree<ValueType>::keep_balance(TreeNode<ValueType> *root) {
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
            root->right = right_rotate(root->right);
        root = left_rotate(root); 
    }
    return update(root);
}

template<typename ValueType>
TreeNode<ValueType> *AVLTree<ValueType>::__insert(TreeNode<ValueType> *root, ValueType val) {
    if (root == NIL) return new TreeNode<ValueType>(val);
    if (root->__val == val) return root;
    if (root->__val < val) root->right = __insert(root->right, val);
    else root->left = __insert(root->left, val);
    return keep_balance(root);
}

template<typename ValueType>
void AVLTree<ValueType>::erase(ValueType val) {
    this->__root = this->__erase(this->__root, val);
}

template<typename ValueType>
TreeNode<ValueType> *AVLTree<ValueType>::predecessor(TreeNode<ValueType> *root) {
    TreeNode<ValueType> *temp = root->left;
    while (temp->right != NIL) temp = temp->right;
    return temp;
}

template<typename ValueType>
TreeNode<ValueType> *AVLTree<ValueType>::__erase(TreeNode<ValueType> *root, ValueType val) {
    if (root == NIL) return root;
    if (root->__val < val) root->right = __erase(root->right, val);
    else if (root->__val > val) root->left = __erase(root->left, val);
    else {
        if ((root->left == NIL) || (root->right == NIL)) {
            TreeNode<ValueType> *temp = (root->left == NIL) ? root->right : root->left;
            delete root;
            return temp;
        }
        TreeNode<ValueType> *temp = predecessor(root);
        root->__val = temp->__val;
        root->left = __erase(root->left, temp->__val);
    }
    return keep_balance(root);
}

template<typename ValueType>
void AVLTree<ValueType>::inorder() {
    __inorder(this->__root);
    cout << endl;
}

template<typename ValueType>
void AVLTree<ValueType>::__inorder(TreeNode<ValueType> *root) {
    if (root == NIL) return ;
    __inorder(root->left);
    cout << root->__val << " ";
    __inorder(root->right);
}

int main() {
    srand(time(0));
    AVLTree<int> IntTree;
    AVLTree<string> StringTree;
    for (int i = 0; i < 20; i++) {
        int temp = rand() % 1000;
        IntTree.insert(temp);
        IntTree.inorder();
    }
    string str;
    while ((cin >> str)) {
        StringTree.insert(str);
        StringTree.inorder();
    }
    #if 0
    int n;
    while ((cin >> n)) {
        tree.erase(n);
        tree.inorder();
    }
    #endif
    return 0;
}
