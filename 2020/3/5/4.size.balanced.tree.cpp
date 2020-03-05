/*************************************************************************
	> File Name: 4.size.balanced.tree.cpp
	> Author:赵睿 
	> Mail: 1767153298@qq.com
	> Created Time: 2020年03月05日 星期四 19时59分57秒
 ************************************************************************/

#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<ctime>
#include<cmath>
using namespace std;

typedef struct Node {
    int value, cnt;
    struct Node *lchild, *rchild;
} Node;

Node _NIL, *NIL = &_NIL;
__attribute__((constructor)) 
void initNIL() {
    NIL->cnt = 0;
    NIL->lchild = NIL->rchild = NIL;
}

Node *getNewNode(int value) {
    Node *p = (Node *) malloc(sizeof(Node));
    p->value = value;
    p->cnt = 1;
    p->lchild = p->rchild = NIL;
    return p;
}

void update(Node *root) {
    int l = root->lchild->cnt;
    int r = root->rchild->cnt;
    root->cnt = 1 + l + r;
}

Node *maintain(Node *root);

Node *left_rotate(Node *root) {
    Node *temp = root->rchild;
    root->rchild = temp->lchild;
    temp->lchild = root;
    return temp;
}

Node *right_rotate(Node *root) {
    Node *temp = root->lchild;
    root->lchild = temp->rchild;
    temp->rchild = root;
    return temp;
}

Node *maintain(Node *root) {
    int ll, lr, rl, rr, lg, rg;
    ll = root->lchild->lchild->cnt;
    lr = root->lchild->rchild->cnt;
    rl = root->rchild->lchild->cnt;
    rr = root->rchild->rchild->cnt;
    if (root->rchild->cnt < ll) {
        root = right_rotate(root);
        root->rchild = maintain(root->rchild);
        root = maintain(root);
    } else if (root->rchild->cnt < lr) {
        root->lchild = left_rotate(root->lchild);
        root = right_rotate(root);
        root->lchild = maintain(root->lchild);
        root->rchild = maintain(root->rchild);
        root = maintain(root);
    } else if (root->lchild->cnt < rr) {
        root = left_rotate(root);
        root->lchild = maintain(root->lchild);
        root = maintain(root);
    } else if (root->lchild->cnt < rl){
        root->rchild = right_rotate(root->rchild);
        root = left_rotate(root);
        root->lchild = maintain(root->lchild);
        root->rchild = maintain(root->rchild);
        root = maintain(root);
    }
    update(root);
    return root;
}

Node *insert(Node *root, int value) {
    if (root == NIL) return getNewNode(value);
    if (root->value == value) return root;
    if (root->value < value) root->rchild = insert(root->rchild, value);
    else root->lchild = insert(root->lchild, value);
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
    printf("%d[%d, %d]\n", root->value, root->lchild->value, root->rchild->value);
    output(root->lchild);
    output(root->rchild);
}

void check(Node *root) {
    if (root == NIL) return ;
    printf("%d, cnt = %d\n", root->value, root->cnt);
    check(root->lchild);
    check(root->rchild);
}

int main() {
    Node *root = NIL;
    for (int i = 1; i <= 10; i++) {
        root = insert(root, i); 
        output(root);
        printf("\n");
        check(root);
        printf("\n");
    }
    return 0;
}
