/*************************************************************************
	> File Name: 2.AVL.cpp
	> Author:赵睿 
	> Mail: 1767153298@qq.com
	> Created Time: 2020年04月23日 星期四 18时16分23秒
 ************************************************************************/

#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<ctime>
using namespace std;
#define H(root) (root)->h
#define L(root) (root)->lchild
#define R(root) (root)->rchild
#define KEY(root) (root)->key

typedef struct Node {
    int key, h;
    struct Node *lchild, *rchild;
} Node;

Node __NIL;
#define NIL (&__NIL)
__attribute__((constructor)) 
void init_NIL() {
    NIL->key = -1;
    NIL->h = 0;
    NIL->lchild = NIL->rchild = NIL;
}

Node *GetNewNode(int key) {
    Node *node = (Node *) calloc(sizeof(Node), 1);
    node->key = key;
    node->h = 1;
    node->lchild = node->rchild = NIL;
    return node;
}

void update_height(Node *root) {
    root->h = (H(L(root)) > H(R(root)) ? H(L(root)) : H(R(root))) + 1;
}

Node *left_rotate(Node *root) {
    Node *temp = root->rchild;    
    root->rchild = temp->lchild;
    temp->lchild = root;
    update_height(root);
    update_height(temp);
    return temp;
}

Node *right_rotate(Node *root) { 
    Node *temp = root->lchild;    
    root->lchild = temp->rchild;
    temp->rchild = root;
    update_height(root);
    update_height(temp);
    return temp;
}



Node *maintain(Node *root) {
    if (abs(H(L(root)) - H(R(root))) <= 1) return root;
    if (H(L(root)) > H(R(root))) {
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

Node *insert(Node *root, int key) {
    if (root == NIL) return GetNewNode(key);
    if (root->key == key) return root;
    if (root->key < key) root->rchild = insert(root->rchild, key);
    else root->lchild = insert(root->lchild, key);
    update_height(root);
    return maintain(root);
}

Node *predecessor(Node *root) {
    Node *temp = root->lchild;
    while (temp->rchild != NIL) temp = temp->rchild;
    return temp;
}

Node *erase(Node *root, int key) {
    if (root == NIL) return root;
    if (root->key > key) root->lchild = erase(root->lchild, key);
    if (root->key < key) root->rchild = erase(root->rchild, key);
    if (root->key == key) {
        if (root->lchild == NIL || root->rchild == NIL) {
            Node *temp = root->lchild == NIL ? root->rchild : root->lchild;
            free(root);
            return temp;
        } else {
            Node *temp = predecessor(root);
            root->key = temp->key;
            root->lchild = erase(root->lchild, temp->key);
        }
    }
    update_height(root);
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
    printf("(%d %d %d)\n", KEY(root), KEY(root->lchild), KEY(root->rchild));
    output(root->lchild);
    output(root->rchild);
}
 
int main() {
    srand(time(0));
    Node *root = NIL;
    #define MAX_OP 20
    int val;
    for (int i = 0; i < MAX_OP; i++) {
        int val = rand() % 100;
        root = insert(root, val);
    }
    output(root);
    while (~scanf("%d", &val)) {
        printf("erase %d from AVL tree\n", val);
        root = erase(root, val);
        output(root);
    }
    return 0;
}
