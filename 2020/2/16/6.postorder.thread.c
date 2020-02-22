/*************************************************************************
	> File Name: 6.postorder.thread.c
	> Author:赵睿 
	> Mail: 1767153298@qq.com
	> Created Time: 2020年02月16日 星期日 15时43分35秒
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>
#define NORMAL 0
#define THREAD 1
#define LEFT 0
#define RIGHT 1
#define ROOT -1

typedef struct node {
    int data;
    struct node *lchild, *rchild, *parent;
    int ltag, rtag;
    int place;
} Node;

typedef struct tree {
    Node *root;
} Tree;

Node *NewNode(int val) {
    Node *node = (Node *) malloc(sizeof(Node));
    node->data = val;
    node->rchild = node->lchild = node->parent = NULL;
    node->ltag = node->rtag = NORMAL;
    node->place = ROOT;
    return node;
}
    
Tree *NewTree() {
    Tree *tree = (Tree *) malloc(sizeof(Tree));
    tree->root = NULL;
    return tree;
}

Node *insertNode(Node *pre, Node *root, int val) {
    if (!root) {
        Node *ret = NewNode(val);
        ret->parent = pre;
        if (pre) {
            if (ret->data > pre->data) ret->place = RIGHT;
            else ret->place = LEFT;
        }
        return ret;
    }
    if (root->data == val) return root;
    if (val < root->data) root->lchild = insertNode(root, root->lchild, val);
    else root->rchild = insertNode(root, root->rchild, val);
    return root;
}

void insert(Tree *tree, int val) {
    if (!tree) return ;
    tree->root = insertNode(NULL, tree->root, val);
    return ;
}

void post_orderNode(Node *root) {
    if (!root) return ;
    if (root->ltag == NORMAL) post_orderNode(root->lchild);
    if (root->rtag == NORMAL) post_orderNode(root->rchild);
    printf("%d ", root->data);
    return ;
}

void post_orderTree(Tree *tree) {
    if (!tree) return ;
    post_orderNode(tree->root);
    printf("\n");
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

void buildThreadNode(Node *root) {
    if (!root) return ;
    static Node *pre = NULL;
    buildThreadNode(root->lchild);
    buildThreadNode(root->rchild);
    if (!root->lchild) {
        root->lchild = pre;
        root->ltag = THREAD;
    }
    if (pre && !pre->rchild) {
        pre->rchild = root;
        pre->rtag = THREAD;
    }
    pre = root;
    return ;
}

void buildThreadTree(Tree *tree) {
    if (!tree) return ;
    buildThreadNode(tree->root);
    return ;
}

Node *most_left(Node *root) {
    if (!root) return NULL;
    while (root && root->ltag == NORMAL) root = root->lchild;
    return root;
}

void outputNode(Node *root) {
    if (!root) return ;
    Node *p = root; 
    Node *pre = NULL;
    while (p) {
        p = most_left(p);
        while (p && p->rtag == THREAD) {
            printf("%d ", p->data);
            pre = p;
            p = p->rchild;
        }
        if (p == root) return ;
        while (p && p->rchild == pre) {
            printf("%d ", p->data);
            pre = p;
            p = p->parent;
        }
        if (p && p->rtag == NORMAL) p = p->rchild;
    }
    return ;
}

void outputTree(Tree *tree) {
    if (!tree) return ;
    outputNode(tree->root);
    printf("\n");
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

int main() {
    srand(time(0));
    Tree *tree = NewTree();
    for (int i = 1; i <= 10; i++) {
        int val = rand() % 100;
        insert(tree, val);
    }
    post_orderTree(tree);
    pre_orderTree(tree);
    buildThreadTree(tree); 
    post_orderTree(tree);
    pre_orderTree(tree);
    outputTree(tree);
    return 0;
}
