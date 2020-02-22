/*************************************************************************
	> File Name: 5.thread.preorder.c
	> Author:赵睿 
	> Mail: 1767153298@qq.com
	> Created Time: 2020年02月16日 星期日 14时22分47秒
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>
#define NORMAL 0
#define THREAD 1

typedef struct node {
    int data;
    struct node *lchild, *rchild;
    int ltag, rtag;
} Node;

typedef struct tree {
    Node *root;
} Tree;

Node *NewNode(int val) {
    Node *node = (Node *) malloc(sizeof(Node));
    node->data = val;
    node->lchild = node->rchild;
    node->ltag = node->rtag = NORMAL;
    return node;
}

Tree *NewTree() {
    Tree *tree = (Tree *) malloc(sizeof(Tree));
    tree->root = NULL;
    return tree;
}

Node *insertNode(Node *root, int val) {
    if (!root) return NewNode(val);
    if (root->data == val) return root;
    if (val < root->data) root->lchild = insertNode(root->lchild, val);
    else root->rchild = insertNode(root->rchild, val);
    return root;
}

void insert(Tree *tree, int val) {
    if (!tree) return ;
    tree->root = insertNode(tree->root, val);
    return ;
}

void clearNode(Node *root) {
    if (!root) return ;
    clearNode(root->lchild);
    clearNode(root->rchild);
    free(root);
    return ;
}

void clearTree(Tree *tree) {
    if (!tree) return ;
    clearNode(tree->root);
    free(tree);
    return ;
}

void pre_orderNode(Node *root) {
    if (!root) return ;
    printf("%d ", root->data);
    if (root->ltag == NORMAL) pre_orderNode(root->lchild);
    if (root->rtag == NORMAL) pre_orderNode(root->rchild);
    return ;
}

void pre_orderTree(Tree *tree) {
    if (!tree) return ;
    pre_orderNode(tree->root);
    printf("\n");
    return ;
}

void buildThreadNode(Node *root) {
    if (!root) return ;
    static Node *pre = NULL;
    if (!root->lchild) {
        root->lchild = pre;
        root->ltag = THREAD;
    }
    if (pre && !pre->rchild) {
        pre->rchild = root;
        pre->rtag = THREAD;
    }
    pre = root;
    if (root->ltag == NORMAL) buildThreadNode(root->lchild);
    if (root->rtag == NORMAL) buildThreadNode(root->rchild);
    return ;
}

void buildThreadTree(Tree *tree) {
    if (!tree) return ;
    buildThreadNode(tree->root);
    return ;
}

void outputNode(Node *root) {
    if (!root) return ;
    while (root) {
        printf("%d ", root->data);
        if (root->ltag == NORMAL) root = root->lchild;
        else root = root->rchild;
    }
    return ;
}

void output(Tree *tree) {
    if (!tree) return ;
    outputNode(tree->root);
    printf("\n");
    return ;
}

int main() {
    srand(time(0));
    Tree *tree = NewTree();
    for (int i = 1; i <= 10; i++) {
        int val = rand() % 100;
        insert(tree, val);
    }
    pre_orderTree(tree);
    buildThreadTree(tree);
    output(tree);
    return 0;
}
