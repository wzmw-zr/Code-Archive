/*************************************************************************
	> File Name: 6.binary.tree.c
	> Author:赵睿 
	> Mail: 1767153298@qq.com
	> Created Time: 2020年02月14日 星期五 18时14分09秒
 ************************************************************************/

#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int data;
    struct node *lchild, *rchild;
}Node;

Node* init(int data) {
    Node *node = (Node *) malloc(sizeof(Node));
    node->data = data;
    node->lchild = node->rchild = NULL;
    return node;
}

void preorder(Node *node) {
    printf("%d ", node->data);
    if (node->lchild) preorder(node->lchild);
    if (node->rchild) preorder(node->rchild);
}

void inorder(Node *node) {
    if (node->lchild) inorder(node->lchild); 
    printf("%d ", node->data);
    if (node->rchild) inorder(node->rchild);
}

void postorder(Node *node) {
    if (node->lchild) postorder(node->lchild); 
    if (node->rchild) postorder(node->rchild);
    printf("%d ", node->data);
}

Node* build_demo() {
    Node *node = init(4); 
    node->lchild = init(2);
    node->rchild = init(6);
    node->lchild->lchild = init(1);
    node->lchild->rchild = init(3);
    node->rchild->lchild = init(5);
    node->rchild->rchild = init(7);
    return node;
}

void clear(Node *node) {
    if (node->lchild) clear(node->lchild);
    if (node->rchild) clear(node->rchild);
    free(node);
}

int main() {
    Node *node = build_demo();
    preorder(node);
    printf("\n");
    inorder(node);
    printf("\n");
    postorder(node);
    printf("\n");
    clear(node);
    return 0;
}
