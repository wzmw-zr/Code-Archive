/*************************************************************************
> File Name: 1.AVL.cpp
> Author:赵睿 
> Mail: 1767153298@qq.com
> Created Time: 2020年08月09日 星期日 07时50分20秒
************************************************************************/

#include<iostream>
using namespace std;

template<typename ValueType>
class TreeNode {
public :
    TreeNode();
    TreeNode(ValueType val);
    ~TreeNode();

    ValueType __val;
    int __height;
    TreeNode *left;
    TreeNode *right;
};


template<typename ValueType>
class Tree {
public:
    typedef TreeNode<ValueType> NodeType;
    Tree();
    NodeType *left_rotate(NodeType *root);
    NodeType *right_rotate(NodeType *root);
    NodeType *insert_node(NodeType *root, ValueType val);
    NodeType *keep_balance(NodeType *root);
    NodeType *predecessor(NodeType *root);
    NodeType *erase_node(NodeType *root, ValueType val);
    NodeType *update(NodeType *root);
    void preorder(NodeType *root);
    void inorder(NodeType *root);
    void postorder(NodeType *root);
    void delete_tree(NodeType *root);
    ~Tree();

    NodeType *__root;
    static NodeType __NIL;
    static NodeType *NIL;
};

template<typename ValueType>
TreeNode<ValueType> Tree<ValueType>::__NIL;

template<typename ValueType>
TreeNode<ValueType> *Tree<ValueType>::NIL;

template<typename ValueType>
TreeNode<ValueType>::TreeNode()
: __height(0)
, left(this)
, right(this) {}

template<typename ValueType>
TreeNode<ValueType>::TreeNode(ValueType val)
: __val(val)
, __height(1)
, left(Tree<ValueType>::NIL)
, right(Tree<ValueType>::NIL) {}

template<typename ValueType>
TreeNode<ValueType>::~TreeNode() {}


template<typename ValueType>
Tree<ValueType>::Tree() {
    NIL = &__NIL;
    NIL->__height = 0;
    NIL->left = NIL;
    NIL->right = NIL;
    __root = NIL;
}

template<typename ValueType>
void Tree<ValueType>::delete_tree(TreeNode<ValueType> *root) {
    if (root == NIL) return ;
    delete_tree(root->left);
    delete_tree(root->right);
    delete root;
}

template<typename ValueType>
Tree<ValueType>::~Tree() {
    this->delete_tree(this->__root);
}

template<typename ValueType>
TreeNode<ValueType> *Tree<ValueType>::left_rotate(TreeNode<ValueType> *root) {
    TreeNode<ValueType> *temp = root->right;
    root->right = temp->left;
    temp->left = root;
    root = update(root);
    return update(temp);
}

template<typename ValueType>
TreeNode<ValueType> *Tree<ValueType>::right_rotate(TreeNode<ValueType> *root) {
    TreeNode<ValueType> *temp = root->left;
    root->left = temp->right;
    temp->right = root;
    root = update(root);
    return update(temp);
}

template<typename ValueType>
TreeNode<ValueType> *Tree<ValueType>::update(TreeNode<ValueType> *root) {
    if (root == NIL) return root;
    root->__height = max(root->left->__height, root->right->__height) + 1;
    return root;
}

template<typename ValueType>
TreeNode<ValueType> *Tree<ValueType>::keep_balance(TreeNode<ValueType> *root) {
    if (root == NIL) return root;
    int l_h = root->left->__height;
    int r_h = root->right->__height;
    if (abs(l_h - r_h) <= 1) return update(root);
    if (l_h > r_h) {
        if (root->left->left->__height < root->left->right->__height)
            root->left = left_rotate(root->left);
        return right_rotate(root);
    } else {
        if (root->right->right->__height < root->right->left->__height)  
            root->right = right_rotate(root->right);
        return left_rotate(root);
    }
    return update(root);
}

template<typename ValueType>
TreeNode<ValueType> *Tree<ValueType>::insert_node(TreeNode<ValueType> *root, ValueType val) {
    typedef TreeNode<ValueType> NodeType;
    if (root == NIL) return new NodeType(val);
    if (root->__val == val) return root;
    if (root->__val < val) root->right = insert_node(root->right, val);
    else root->left = insert_node(root->left, val);
    return keep_balance(root);
}

template<typename ValueType>
TreeNode<ValueType> *Tree<ValueType>::predecessor(TreeNode<ValueType> *root) {
    TreeNode<ValueType> *temp = root->left;
    while (temp->right != NIL) temp = temp->right;
    return temp;
}

template<typename ValueType>
TreeNode<ValueType> *Tree<ValueType>::erase_node(TreeNode<ValueType> *root, ValueType val) { 
    typedef TreeNode<ValueType> NodeType;
    if (root == NIL) return root;
    if (root->__val < val) root->right = erase_node(root->right, val);
    else if (root->__val > val) root->left = erase_node(root->left, val);
    else {
        if ((root->left == NIL) || (root->right == NIL)) {
            NodeType *tmp = (root->left == NIL) ? root->right : root->left;
            delete root;
            return tmp;
        } 
        NodeType *pre = predecessor(root);
        root->__val = pre->__val;
        root->left = erase_node(root->left, pre->__val);
    }
    return keep_balance(root);
}

template<typename ValueType>
void Tree<ValueType>::preorder(TreeNode<ValueType> *root) {
    if (root == NIL) return ;
    cout << root->__val << " ";
    preorder(root->left);
    preorder(root->right);
}

template<typename ValueType>
void Tree<ValueType>::inorder(TreeNode<ValueType> *root) {
    if (root == NIL) return ;
    preorder(root->left);
    cout << root->__val << " ";
    preorder(root->right);
}

template<typename ValueType>
void Tree<ValueType>::postorder(TreeNode<ValueType> *root) {
    if (root == NIL) return ;
    preorder(root->left);
    preorder(root->right);
    cout << root->__val << " ";
}

int main() {
    Tree<int> tree;
    tree.__root = tree.insert_node(tree.__root, 10);
    tree.__root = tree.insert_node(tree.__root, 9);
    tree.__root = tree.insert_node(tree.__root, 8);
    tree.__root = tree.insert_node(tree.__root, 7);
    tree.__root = tree.insert_node(tree.__root, 6);
    tree.__root = tree.insert_node(tree.__root, 5);
    tree.inorder(tree.__root);
    cout << endl;
    tree.__root = tree.erase_node(tree.__root, 10);
    tree.inorder(tree.__root);
    cout << endl;
    return 0;
}
