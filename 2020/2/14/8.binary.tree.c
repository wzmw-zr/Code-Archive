/*************************************************************************
	> File Name: 8.binary.tree.c
	> Author:赵睿 
	> Mail: 1767153298@qq.com
	> Created Time: 2020年02月14日 星期五 22时19分57秒
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define max_n 50

typedef struct node {
    char c;
    struct node *lchild, *rchild;
} Node;

typedef struct tree {
    Node *root;
} Tree;

Node *newNode(char c) {
    Node *n = (Node *) malloc(sizeof(Node));
    n->c = c;
    n->lchild = n->rchild = NULL;
    return n;
}

Tree *newTree() {
    Tree *t = (Tree *) malloc(sizeof(Tree));
    t->root = NULL;
    return t;
}



void clearNode(Node *root) {
    if (!root) return ;
    clearNode(root->lchild);
    clearNode(root->rchild);
    free(root);
    return ;
}

void clearTree(Tree *t) {
    if (!t) return ;
    clearNode(t->root);
    free(t);
    return ;
}

Node *build(char *pre_str, char *in_str, int len) {
    Node *p = newNode(pre_str[0]);
    int pos = strchr(in_str, pre_str[0]) - in_str;
    if (pos > 0) {
        p->lchild = build(pre_str + 1, in_str, pos);
    }
    if (len - pos - 1 > 0) {
        p->rchild = build(pre_str + pos + 1, in_str + pos + 1, len - pos - 1);
    }
    return p;
}

void postorderNode(Node *root) {
    if (!root) return ;
    postorderNode(root->lchild);
    postorderNode(root->rchild);
    printf("%c", root->c);
    return ;
}

void postorder(Tree *t) {
    if (!t) return ;
    postorderNode(t->root);
    printf("\n");
    return ;
}

void swapNode(Node *root) {
    if (!root) return ;
    Node *tmp = root->lchild;
    root->lchild = root->rchild;
    root->rchild = tmp;
    swapNode(root->lchild);
    swapNode(root->rchild);
    return ;
}

void swap(Tree *t) {
    if (!t) return ;
    swapNode(t->root);
    return ;
}

int main() {
    char pre_str[max_n + 5] , in_str[max_n + 5]; 
    Tree *t = newTree();
    scanf("%s\n", pre_str);
    scanf("%s\n", in_str);
    t->root = build(pre_str, in_str, strlen(pre_str));
    postorder(t);
    swap(t); 
    postorder(t);
    clearTree(t);
    return 0;
}
