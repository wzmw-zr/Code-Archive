/*************************************************************************
	> File Name: 3.AVL.tree.cpp
	> Author:赵睿 
	> Mail: 1767153298@qq.com
	> Created Time: 2020年03月05日 星期四 19时06分07秒
 ************************************************************************/

#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<ctime>
#include<cmath>
using namespace std;

typedef struct Node {
    int data, height;
    struct Node *lchild, *rchild; 
} Node;

Node _NIL, *NIL = &_NIL;
__attribute__((constructor)) 
void init_NIL() {
    NIL->height = 0;
    NIL->lchild = NIL;
    NIL->rchild = NIL;
}

Node *getNewNode(int val) {
    Node *p = (Node *) malloc(sizeof(Node));
    p->data = val;
    p->height = 1;
    p->lchild = p->rchild = NIL;
    return p;
}

void update(Node *root) {
    int l = root->lchild->height;
    int r = root->rchild->height;
    root->height = 1 + (l > r ? l : r);
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
    if (abs(root->lchild->height - root->rchild->height) <= 1) {
        update(root);
        return root;
    }
    if (root->lchild->height > root->rchild->height) {
        if (root->lchild->rchild->height > root->lchild->lchild->height) {
            root->lchild = left_rotate(root->lchild);
        }
        root = right_rotate(root);
    } else {
        if (root->rchild->lchild->height > root->rchild->rchild->height) {
            root->rchild = right_rotate(root->rchild);
        }
        root = left_rotate(root);
    }
    return root;
}

Node *insert(Node *root, int val) {
    if (root == NIL) return getNewNode(val);
    if (root->data == val) return root;
    if (root->data < val) root->rchild = insert(root->rchild, val);
    else root->lchild = insert(root->lchild, val);
    return maintain(root);
}

Node *predecessor(Node *root) {
    Node *temp = root->lchild;
    while (temp->rchild != NIL) temp = temp->rchild;
    return temp;
}

Node *erase(Node *root, int val) {
    if (root == NIL) return root;
    if (root->data < val) root->rchild = erase(root->rchild, val);
    else if (root->data > val) root->lchild = erase(root->lchild, val);
    else {
        if (root->lchild == NIL || root->rchild == NIL) {
            Node *temp = root->lchild == NIL ? root->rchild : root->lchild;
            free(root);
            return temp;
        }
        Node *temp = predecessor(root);
        root->data = temp->data;
        root->lchild = erase(root->lchild, temp->data);
    }
    return maintain(root);
}


void clear(Node *root) {
    if (root == NIL) return ;
    clear(root->lchild);
    clear(root->rchild);
    free(root);
}

void output(Node *root) {
    if (root == NIL) return ;
    printf("%d[%d, %d]\n", root->data, root->lchild->data, root->rchild->data);
    output(root->lchild);
    output(root->rchild);
}

int main() { 
    Node *root = NIL;
    for (int i = 1; i <= 10; i++) {
        root = insert(root, i);
        output(root);
        printf("\n");
    }
    for (int i = 10; i >= 3; i--) {
        printf("i = %d\n", i);
        root = erase(root, i);
        output(root);
        printf("\n");
    }
    return 0;
}
