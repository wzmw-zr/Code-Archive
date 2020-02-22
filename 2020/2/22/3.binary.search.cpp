/*************************************************************************
	> File Name: 3.binary.search.cpp
	> Author:赵睿 
	> Mail: 1767153298@qq.com
	> Created Time: 2020年02月22日 星期六 16时38分31秒
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct Node {
    int key;
    struct Node *lchild, *rchild;
} Node;

Node *getNewNode(int key) {
    Node *p = (Node *) malloc(sizeof(Node));
    p->key = key;
    p->rchild = p->lchild = NULL;
    return p;
} 

Node *insert(Node *root, int key) {
    if (!root) return getNewNode(key);
    if (root->key == key) return root;
    if (key < root->key) root->lchild = insert(root->lchild, key);
    else root->rchild = insert(root->rchild, key);
    return root;
}

Node *predecessor(Node *root) {
    Node *temp = root->lchild;
    while (temp->rchild) temp = temp->rchild;
    return temp;
}

Node *erase(Node *root, int key) {
    if (!root) return root;
    if (key < root->key) root->lchild = erase(root->lchild, key);
    else if (key > root->key) root->rchild = erase(root->rchild, key);
    else {
        if (!root->lchild || !root->rchild) {
            Node *temp = root->lchild ? root->lchild : root->rchild;
            free(root);
            return temp;
        } else {
            Node *temp = predecessor(root);
            root->key = temp->key;
            root->lchild = erase(root->lchild, temp->key);
        }
    }
    return root;
}

void __inorder(Node *root) {
    if (!root) return ;
    __inorder(root->lchild);
    printf("%d ", root->key);
    __inorder(root->rchild);
}

void inorder(Node *root) {
    printf("inorder output : ");
    __inorder(root);
    printf("\n");
} 

void clearNode(Node *p) {
    if(!p) return ;
    clearNode(p->lchild);
    clearNode(p->rchild);
    free(p);
}

int main() {
    int op, val;
    Node *root = NULL;
    while (~scanf("%d%d", &op, &val)) {
        switch (op) {
            case 1: root = insert(root, val); break;
            case 2: root = erase(root, val); break;
        }
        inorder(root);
    }
    clearNode(root);
    return 0;
}
