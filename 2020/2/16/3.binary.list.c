/*************************************************************************
	> File Name: 3.binary.list.c
	> Author:赵睿 
	> Mail: 1767153298@qq.com
	> Created Time: 2020年02月16日 星期日 08时59分01秒
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define max_n 1000

typedef struct node {
    char data;
    struct node *lchild, *rchild;
} Node;

typedef struct tree {
    Node *root;
} Tree;

Node *NewNode(char c) {
    Node *node = (Node *) malloc(sizeof(Node));
    node->data = c;
    node->lchild = node->rchild = NULL;
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
    return ;
}

void clearTree(Tree *tree) {
    if (!tree) return ;
    clearNode(tree->root);
    free(tree);
    return ;
}

Node *build(Node *root, char parent, char name, char place) {
    if (!root && parent == '^' && name != '^') return NewNode(name);  
    if (!root) return NULL;
    if (root->data == parent) {
        if (place == 'L') root->lchild = NewNode(name);
        if (place == 'R') root->rchild = NewNode(name);
        return root;
    }
    root->lchild = build(root->lchild, parent, name, place);
    root->rchild = build(root->rchild, parent, name, place);
    return root;
}

void outputNode(Node *root) {
    if (!root) return ;
    printf("%c", root->data);
    if (root->lchild) {
        printf("(");
        outputNode(root->lchild);
        if (!root->rchild) printf(")");
    }
    if (root->rchild) {
        if (!root->lchild) printf("(");
        printf(",");
        outputNode(root->rchild);
        printf(")");
    }
    return ;
}

void outputTree(Tree *tree) {
    if (!tree) return ;
    outputNode(tree->root);
    printf("\n");
    return ;
}

int main() {
    char str[5];
    Tree *tree = NewTree();
    while (scanf("%[^\n]s", str)) {
        str[1] != '^' && getchar();
        tree->root = build(tree->root, str[0], str[1], str[2]); 
    }
    outputTree(tree);
    clearTree(tree);
    return 0;
}
