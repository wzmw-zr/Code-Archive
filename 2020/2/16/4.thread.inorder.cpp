/*************************************************************************
	> File Name: 4.thread.inorder.cpp
	> Author:赵睿 
	> Mail: 1767153298@qq.com
	> Created Time: 2020年02月16日 星期日 10时31分21秒
 ************************************************************************/
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>
#include<unistd.h>
#define max_n 10
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
    node->lchild = node->rchild = NULL;
    node->ltag = node->rtag = NORMAL;
    return node;
}

Tree *NewTree() {
    Tree *tree = (Tree *) malloc(sizeof(Tree));
    tree->root = NULL;
    return tree;
}

void clearNode(Node *root) {
    if (!root) return ;
    clearNode(root->lchild);
    clearNode(root->rchild);
    free(root);
}

void clearTree(Tree *tree) {
    if (!tree) return ;
    clearNode(tree->root);
    return ;
}

Node *insertNode(Node *root, int val) {
    if (!root) return NewNode(val);
    if (root->data == val) return root;
    if (val < root->data) root->lchild = insertNode(root->lchild, val);
    else root->rchild = insertNode(root->rchild, val);
    return root;
}

void insertTree(Tree *tree, int val) {
    if (!tree) return ;
    tree->root = insertNode(tree->root, val);
    return ;
}

void build_in_threadNode(Node *root) {
    if (!root) return ;
    static Node *pre = NULL;
    build_in_threadNode(root->lchild);
    if (!root->lchild) {
        root->lchild = pre;
        root->ltag = THREAD;
    }
    if (pre && !pre->rchild) {
        pre->rchild = root;
        pre->rtag = THREAD;
    }
    pre = root;
    build_in_threadNode(root->rchild);
    return ;
}

void build_in_thread(Tree *tree) {
    if (!tree) return ;
    build_in_threadNode(tree->root);
    return ;
}

Node *most_left(Node *root) {
    while (root && root->ltag == NORMAL) root = root->lchild;
    return root;
}

void outputNode(Node *root) {
    int count = 0;
    Node *pre = most_left(root);
    while (pre && count <= 10) {
        printf("%d ", pre->data);
        if (pre->rtag == THREAD) {
            pre = pre->rchild;
        } else {
            pre = most_left(pre->rchild);
        }
        count++;
    }
    return ;
}

void outputTree(Tree *tree) {
    if (!tree) return ;
    printf("tree = ");
    outputNode(tree->root);
    printf("\n");
    return ;
}


void in_orderNode(Node *root) {
    if (!root) return ;
    if (root->ltag == NORMAL) in_orderNode(root->lchild);
    printf("%d ", root->data);
    if (root->rtag == NORMAL) in_orderNode(root->rchild);
    return ;
}

void in_orderTree(Tree *tree) {
    if (!tree) return ;
    in_orderNode(tree->root);
    printf("\n");
    return ;
}

int main() {
    srand(time(0));
    Tree *tree = NewTree();
    for (int i = 1; i <= max_n; i++) {
        int val = rand() % 100;
        insertTree(tree, val); 
    }
    build_in_thread(tree);
    in_orderTree(tree);
    outputTree(tree);
    return 0;
}
