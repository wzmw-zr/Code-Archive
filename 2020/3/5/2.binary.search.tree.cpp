/*************************************************************************
	> File Name: 2.binary.search.tree.cpp
	> Author:赵睿 
	> Mail: 1767153298@qq.com
	> Created Time: 2020年03月05日 星期四 18时51分08秒
 ************************************************************************/

#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<ctime>
using namespace std;

typedef struct Node {
    int value;
    struct Node *lchild, *rchild;
} Node;

Node *getNewNode(int value) {
    Node *p = (Node *) malloc(sizeof(Node));
    p->value = value;
    p->lchild = p->rchild = NULL;;
    return p;
}

Node *insert(Node *root, int val) {
    if (root == NULL) return getNewNode(val);
    if (root->value == val) return root;
    if (root->value < val) root->rchild = insert(root->rchild, val);
    else root->lchild = insert(root->lchild, val);
    return root;
}

Node *predecessor(Node *root) {
    Node *temp = root->lchild;
    while (temp->rchild != NULL) temp = temp->rchild; 
    return temp;
}

Node *erase(Node *root, int val) {
    if (root == NULL) return root;
    if (root->value < val) root->rchild = erase(root->rchild, val);
    else if (root->value > val) root->lchild = erase(root->lchild, val);
    else {
        if (root->lchild == NULL || root->rchild == NULL) {
            Node *temp = root->lchild == NULL ? root->rchild : root->lchild;
            free(root);
            return temp;
        }
        Node *temp = predecessor(root);
        root->value = temp->value;
        root->lchild = erase(root->lchild, temp->value);
    }
    return root;
}

void clear(Node *root) {
    if (root == NULL) return ;
    clear(root->lchild);
    clear(root->rchild);
    free(root);
}

void output(Node *root) {
    if (root == NULL) return ;
    output(root->lchild);
    printf("%d ", root->value);
    output(root->rchild);
}

int main() {
    srand(time(0));
    Node *root = NULL;
    int num[20] = {0};
    for (int i = 1; i <= 10; i++) {
        int val = rand() % 100;
        num[i] = val;
        root = insert(root, val);
    }
    output(root); 
    printf("\n");
    for (int i = 1; i <= 5; i++) {
        root = erase(root, num[i]);
        output(root);
        printf("\n");
    }
    return 0;
}
