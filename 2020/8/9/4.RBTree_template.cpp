/*************************************************************************
	> File Name: 4.RBTree_template.cpp
	> Author:赵睿 
	> Mail: 1767153298@qq.com
	> Created Time: 2020年08月09日 星期日 20时15分46秒
 ************************************************************************/

#include<iostream>
#include<ctime>
using namespace std;
#define RED 0
#define BLACK 1
#define DBLACK 2

template<typename ValueType>
class TreeNode {
public :
    ValueType __val;
    int color;
    TreeNode *left;
    TreeNode *right;

    TreeNode();
    TreeNode(ValueType val);
    ~TreeNode();
};

template<typename ValueType>
class RBTree {
public :
    typedef TreeNode<ValueType> NodeType;
    NodeType *__root;
    static NodeType __NIL;
    static NodeType *NIL;

    RBTree();
    ~RBTree();
    void delete_tree(NodeType *root);
    void insert(ValueType val);
    NodeType *__insert(NodeType *root, ValueType val);
    void erase(ValueType val);
    NodeType *__erase(NodeType *root, ValueType val);
    NodeType *left_rotate(NodeType *root);
    NodeType *right_rotate(NodeType *root);
    NodeType *predecessor(NodeType *root);
    NodeType *insert_maintain(NodeType *root);
    NodeType *erase_maintain(NodeType *root);
    bool has_red_child(NodeType *root);

    void inorder();
    void __inorder(NodeType *root);
};

template<typename ValueType>
TreeNode<ValueType> RBTree<ValueType>::__NIL;

template<typename ValueType>
TreeNode<ValueType> *RBTree<ValueType>::NIL = &(RBTree<ValueType>::__NIL);

template<typename ValueType>
TreeNode<ValueType>::TreeNode()
: color(BLACK)
, left(this)
, right(this) {}

template<typename ValueType>
TreeNode<ValueType>::TreeNode(ValueType val)
: __val(val)
, color(RED)
, left(RBTree<ValueType>::NIL)
, right(RBTree<ValueType>::NIL) {}

template<typename ValueType>
TreeNode<ValueType>::~TreeNode() {}

template<typename ValueType>
RBTree<ValueType>::RBTree() 
: __root(this->NIL) {}

template<typename ValueType>
RBTree<ValueType>::~RBTree() {
    delete_tree(this->__root);
}

template<typename ValueType>
void RBTree<ValueType>::delete_tree(TreeNode<ValueType> *root) {
    if (root == NIL) return ;
    delete_tree(root->left);
    delete_tree(root->right);
    delete root;
}

template<typename ValueType>
void RBTree<ValueType>::insert(ValueType val) {
    this->__root = this->__insert(this->__root, val);
    this->__root->color = BLACK;
}

template<typename ValueType>
TreeNode<ValueType> *RBTree<ValueType>::__insert(TreeNode<ValueType> *root, ValueType val) {
    if (root == NIL) return new TreeNode<ValueType>(val);
    if (root->__val == val) return root;
    if (root->__val < val) root->right = __insert(root->right, val);
    else root->left = __insert(root->left, val);
    return insert_maintain(root);
}

template<typename ValueType>
TreeNode<ValueType> *RBTree<ValueType>::left_rotate(TreeNode<ValueType> *root) {
    TreeNode<ValueType> *temp = root->right;
    root->right = temp->left;
    temp->left = root;
    return temp;
}

template<typename ValueType>
TreeNode<ValueType> *RBTree<ValueType>::right_rotate(TreeNode<ValueType> *root) {
    TreeNode<ValueType> *temp = root->left;
    root->left = temp->right;
    temp->right = root;
    return temp;
}

template<typename ValueType>
bool RBTree<ValueType>::has_red_child(TreeNode<ValueType> *root) {
    return (root->left->color == RED) || (root->right->color == RED);
}

template<typename ValueType>
TreeNode<ValueType> *RBTree<ValueType>::insert_maintain(TreeNode<ValueType> *root) {
    if (!has_red_child(root)) return root;
    if (root->left->color == RED && root->right->color == RED) {
        root->color = RED;
        root->left->color = BLACK;
        root->right->color = BLACK;
        return root;
    }
    if (root->left->color == RED) {
        if (!has_red_child(root->left)) return root;
        if (root->left->right->color == RED) 
            root->left = left_rotate(root->left);
        root = right_rotate(root);
    } else {
        if (!has_red_child(root->right)) return root;
        if (root->right->left->color == RED) 
            root->right = right_rotate(root->right);
        root = left_rotate(root); 
    }
    root->left->color = BLACK;
    root->right->color = BLACK;
    root->color = RED;
    return root;
}

template<typename ValueType>
void RBTree<ValueType>::erase(ValueType val) {
    this->__root = this->__erase(this->__root, val);
    this->__root->color = BLACK;
}

template<typename ValueType>
TreeNode<ValueType> *RBTree<ValueType>::predecessor(TreeNode<ValueType> *root) {
    TreeNode<ValueType> *temp = root->left;
    while (temp->right != NIL) temp = temp->right;
    return temp;
}

template<typename ValueType>
TreeNode<ValueType> *RBTree<ValueType>::erase_maintain(TreeNode<ValueType> *root) {
    if ((root->left->color != DBLACK) && (root->right->color != DBLACK)) return root;
    if (root->left->color == DBLACK) {
        if (root->right->color == BLACK) {
            if (!has_red_child(root->right)) {
                root->left->color -= 1;
                root->color += 1;
                root->right->color -= 1;
                return root;
            }
            if (root->right->right->color != RED) {
                root->right = right_rotate(root->right);
                root->right->color = BLACK;
                root->right->right->color = RED;
            }
            root = left_rotate(root);
            root->left->left->color -= 1;
            root->right->color += 1;
            root->color = root->left->color;
            root->left->color = BLACK;
        } else {
            root = left_rotate(root);
            root->color = BLACK;
            root->left->color = RED;
            root->left = erase_maintain(root->left);
        }
    } else {
        if (root->left->color == BLACK) {
            if (!has_red_child(root->left)) {
                root->right->color -= 1;
                root->color += 1;
                root->left->color -= 1;
                return root;
            }
            if (root->left->left->color != RED) {
                root->left = right_rotate(root->left);
                root->left->color = BLACK;
                root->left->left->color = RED;
            }
            root = right_rotate(root);
            root->right->right->color -= 1;
            root->left->color += 1;
            root->color = root->right->color;
            root->right->color = BLACK;
        } else {
            root = right_rotate(root);
            root->color = BLACK;
            root->right->color = RED;
            root->right = erase_maintain(root->right);
        }
    }
    return root;
}

template<typename ValueType>
TreeNode<ValueType> *RBTree<ValueType>::__erase(TreeNode<ValueType> *root, ValueType val) {
    if (root == NIL) return root;
    if (root->__val < val) root->right = __erase(root->right, val);
    else if (root->__val > val) root->left = __erase(root->left, val);
    else {
        if ((root->left == NIL) || (root->right == NIL)) {
            TreeNode<ValueType> *temp = (root->left == NIL) ? root->right : root->left;
            temp->color += root->color;
            delete root;
            return temp;
        }
        TreeNode<ValueType> *temp = predecessor(root);
        root->__val = temp->__val;
        root->left = __erase(root->left, temp->__val);
    }
    return erase_maintain(root);
}

template<typename ValueType>
void RBTree<ValueType>::inorder() {
    __inorder(this->__root);
    cout << endl;
}

template<typename ValueType>
void RBTree<ValueType>::__inorder(TreeNode<ValueType> *root) {
    if (root == NIL) return ;
    __inorder(root->left);
    cout << root->__val << " ";
    __inorder(root->right);
}

int main() {
    RBTree<int> IntTree;
    for (int i = 10; i >= 0; i--) {
        IntTree.insert(i);
        IntTree.inorder();
    }
    int n;
    while ((cin >> n)) {
        IntTree.erase(n);
        IntTree.inorder();
    }
    return 0;
}
