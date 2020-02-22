/*************************************************************************
	> File Name: 7.binary.tree.cpp
	> Author:赵睿 
	> Mail: 1767153298@qq.com
	> Created Time: 2020年02月14日 星期五 21时11分12秒
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>
#include<time.h>


typedef struct node {
    int val;
    struct node *lchild, *rchild;
} Node;

typedef struct tree {
    Node *root;
    int n;
} Tree;

Node *new_node(int val) {
    Node *node = (Node *) malloc(sizeof(Node));
    node->val = val;
    node->lchild = node->rchild = NULL;
    return node;
}

Tree *new_tree() {
    Tree *t = (Tree *) malloc(sizeof(Tree));
    t->root = NULL;
    t->n = 0;
    return t;
}

Node *insertNode(Node *root, int val, int *flag) {
    if (root == NULL) {
        *flag = 1;
        return new_node(val);
    }
    if (root->val == val) return root;
    if (root->val > val) root->lchild = insertNode(root->lchild, val, flag);
    else root->rchild = insertNode(root->rchild, val, flag);
    return root;
}

void insert(Tree *tree, int val) {
    if (!tree) return ;
    int flag = 0;
    tree->root = insertNode(tree->root, val, &flag);
    tree->n += flag;
    return ;
}


void clearNode(Node *node) {
    if (!node) return ;
    clearNode(node->rchild);
    clearNode(node->lchild);
    free(node);
    return ;
}

void clearTree(Tree *tree) {
    if (!tree) return ;
    clearNode(tree->root);
    free(tree);
    return ;
}

void outputNode(Node *root) {
    if (!root) return ;
    printf("%d ", root->val);
    if (root->lchild == NULL && root->rchild == NULL) return ;
    printf("(");
    outputNode(root->lchild);
    printf(",");
    outputNode(root->rchild);
    printf(")");
    return ;
}

void output(Tree *tree) {
    if (!tree) return ;
    printf("tree(%d) = ", tree->n);
    outputNode(tree->root);
    printf("\n");
    return ;
}

int main() {
    srand(time(0));
    #define max_op 20
    Tree *tree = new_tree();
    for (int i = 0; i < max_op; i++) {
        int val = rand() % 100;
        insert(tree, val);
    }
    output(tree);
    clearTree(tree);
    return 0;
}
