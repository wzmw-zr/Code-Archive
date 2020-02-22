/*************************************************************************
	> File Name: 3.binary.tree.c
	> Author:赵睿 
	> Mail: 1767153298@qq.com
	> Created Time: 2020年02月15日 星期六 15时59分41秒
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>

typedef struct node {
    int data;
    struct node *lchild, *rchild;
} Node;

typedef struct tree {
    Node *root;
    int n;
} Tree;

Node *getNewNode(int val) {
    Node *p = (Node *) malloc(sizeof(Node));
    p->data = val;
    p->lchild = p->rchild = NULL;
    return p;
}

Tree *getNewTree() {
    Tree *tree = (Tree *) malloc(sizeof(Tree));
    tree->root = NULL;
    tree->n = 0;
    return tree;
}

Node *insertNode(Node *root, int val, int *flag) {
    if (!root) {
        *flag = 1;
        return getNewNode(val);
    }
    if (root->data == val) return root;
    if (val < root->data) root->lchild = insertNode(root->lchild, val, flag);
    else root->rchild = insertNode(root->rchild, val, flag);
    return root;
}

void insert(Tree *tree, int val) {
    int flag = 0;
    tree->root = insertNode(tree->root, val, &flag);
    tree->n += flag;
    return ;
}

void outputNode(Node *root) {
    if (!root) return ;
    printf("%d", root->data);
    if (!root->lchild && !root->rchild) return ;
    if (root->lchild) {
        printf("(");
        outputNode(root->lchild);
        printf(",");
        if (!root->rchild) printf(")");
    }
    if (root->rchild) {
        if (!root->lchild) printf("(,"); 
        outputNode(root->rchild);
        printf(")");
    }
    return ;
}

void output(Tree *tree) {
    printf("tree(%d) : ", tree->n);
    outputNode(tree->root);
    printf("\n");
    return ;
}

void pre_orderNode(Node *root) {
    if (!root) return ;
    printf("%d ", root->data);
    pre_orderNode(root->lchild);
    pre_orderNode(root->rchild);
    return ;
}

void pre_order(Tree *tree) {
    printf("pre_order : ");
    pre_orderNode(tree->root);
    printf("\n");
    return ;
}

void in_orderNode(Node *root) {
    if (!root) return ;
    in_orderNode(root->lchild);
    printf("%d ", root->data);
    in_orderNode(root->rchild);
    return ;
}

void in_order(Tree *tree) {
    printf("in_order : ");
    in_orderNode(tree->root);
    printf("\n");
    return ;
}

void post_orderNode(Node *root) {
    if (!root) return ;
    post_orderNode(root->lchild);
    post_orderNode(root->rchild);
    printf("%d ", root->data);
    return ;
}

void post_order(Tree *tree) {
    printf("post_order : ");
    post_orderNode(tree->root);
    printf("\n");
    return ;
}

void clear_Node(Node *root) {
    if (!root) return ;
    clear_Node(root->lchild);
    clear_Node(root->rchild);
    free(root);
    return ;
}

void clear_Tree(Tree *tree) {
    if (!tree) return ;
    clear_Node(tree->root);
    free(tree);
    return ;
}

int main() {
    srand(time(0));
    #define max_op 10  
    Tree *tree = getNewTree();
    for (int i = 0; i < max_op; i++) {
        int val = rand() % 100;
        insert(tree, val);
        output(tree);
    }
    pre_order(tree);
    in_order(tree);
    post_order(tree);
    clear_Tree(tree);
    return 0;
}
