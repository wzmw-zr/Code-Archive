/*************************************************************************
	> File Name: 6.AVL.cpp
	> Author:赵睿 
	> Mail: 1767153298@qq.com
	> Created Time: 2020年04月23日 星期四 22时05分28秒
 ************************************************************************/

#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
using namespace std;
#define H(root) (root)->height
#define L(root) (root)->lchild
#define R(root) (root)->rchild
#define V(root) (root)->val

typedef struct Node {
    int val, height;
    struct Node *lchild, *rchild;
} Node;

Node __NIL;
#define NIL (&__NIL)
__attribute__((constructor))
void init() {
    NIL->val = -1;
    NIL->height = 0;
    NIL->lchild = NIL->rchild = NIL;
}

Node *GetNewNode(int x) {
    Node *node = (Node *) calloc(sizeof(Node), 1);
    node->val = x;
    node->height = 1;
    node->lchild = node->rchild = NIL;
    return node;
}

void update(Node *root) {
    int l_h = H(L(root)), r_h = H(R(root));
    H(root) = max(l_h, r_h) + 1;
}

Node *left_rotate(Node *root) {
    Node *temp = root->rchild;
    root->rchild = temp->lchild;
    temp->lchild = root;
    update(root);
    update(temp);
    return temp;
}

Node *right_rotate(Node *root) { 
    Node *temp = root->lchild;
    root->lchild = temp->rchild;
    temp->rchild = root;
    update(root);
    update(temp);
    return temp;
}

Node *maintain(Node *root) {
    int l_h = H(L(root));
    int r_h = H(R(root));
    if (abs(l_h - r_h) <= 1) return root;
    if (l_h > r_h) {
        if (H(L(R(root))) > H(L(L(root)))) 
            root->lchild = left_rotate(root->lchild);
        root = right_rotate(root);
    } else {
        if (H(R(L(root))) > H(R(R(root)))) 
            root->rchild = right_rotate(root->rchild);
        root = left_rotate(root); 
    }
    return root;
}

Node *insert(Node *root, int val) {
    if (root == NIL) return GetNewNode(val);
    if (root->val == val) return root;
    if (root->val > val) root->lchild = insert(root->lchild, val);
    else root->rchild = insert(root->rchild, val);
    update(root);
    return maintain(root);
}

Node *predecessor(Node *root) {
    Node *temp = root->lchild;
    while (temp->rchild != NIL) temp = temp->rchild;
    return temp;
}

Node *erase(Node *root, int val) {
    if (root == NIL) return root;
    if (root->val < val) root->rchild = erase(root->rchild, val);
    if (root->val > val) root->lchild = erase(root->lchild, val);
    if (root->val == val) {
        if (root->lchild == NIL || root->rchild == NIL) {
            Node *temp = root->lchild == NIL ? root->rchild : root->lchild;
            free(root);
            return temp;
        }
        Node *temp = predecessor(root);
        root->val = temp->val;
        root->lchild = erase(root->lchild, temp->val);
    }
    return maintain(root);
}

void clear(Node *root) {
    if (root == NIL) return ;
    clear(root->lchild);
    clear(root->rchild);
    free(root);
}


int main() {
    return 0;
}
