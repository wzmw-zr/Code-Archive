/*************************************************************************
	> File Name: 2.red.black.tree.cpp
	> Author:赵睿 
	> Mail: 1767153298@qq.com
	> Created Time: 2020年03月06日 星期五 13时34分12秒
 ************************************************************************/

#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<ctime>
using namespace std;
#define RED 0
#define BLACK 1
#define DOUBLE_BLACK 2

typedef struct Node {
    int value, color;
    struct Node *lchild, *rchild;
} Node;

Node _NIL, *NIL = &_NIL;
__attribute__((constructor))
void initNIL() {
    NIL->color = BLACK;
    NIL->lchild = NIL->rchild = NIL;
}

Node *getNewNode(int value) {
    Node *p = (Node *) malloc(sizeof(Node));
    p->value = value;
    p->color = RED;
    p->lchild = p->rchild = NIL;
    return p;
}

int hasRedChild(Node *root) {
    return root->lchild->color == RED || root->rchild->color == RED;
}

Node *left_rotate(Node *root) {
    Node *temp = root->rchild;
    root->rchild = temp->lchild;
    temp->lchild = root;
    return temp;
}

Node *right_rotate(Node *root) {
    Node *temp = root->lchild;
    root->lchild = temp->rchild;
    temp->rchild = root;
    return temp;
}

Node *insert_maintain(Node *root) {
    if (!hasRedChild(root)) return root;
    if (root->lchild->color == RED && root->rchild->color == RED) {
        if (!hasRedChild(root->lchild) && !hasRedChild(root->rchild)) return root;
        root->color = RED;
        root->lchild->color = root->rchild->color = BLACK;
        return root;
    }
    if (root->lchild->color == RED) {
        if (!hasRedChild(root->lchild)) return root;
        if (root->lchild->rchild->color == RED) {
            root->lchild = left_rotate(root->lchild);
        }
        root = right_rotate(root);
        root->color = BLACK;
        root->rchild->color = RED;
    } else {
        if (!hasRedChild(root->rchild)) return root;
        if (root->rchild->lchild == RED) {
            root->rchild = right_rotate(root->rchild);
        }
        root = left_rotate(root);
        root->color = BLACK;
        root->lchild->color = RED;
    }
    return root;
}

Node *_insert(Node *root, int value) {
    if (root == NIL) return getNewNode(value);
    if (root->value == value) return root;
    if (root->value < value) root->rchild = _insert(root->rchild, value);
    else root->lchild = _insert(root->lchild, value);
    return insert_maintain(root);
}

Node *insert(Node *root, int value) {
    root = _insert(root, value);
    root->color = BLACK;
    return root;
}

Node *predecessor(Node *root) {
    Node *temp = root->lchild;
    while (temp->rchild != NIL) temp = temp->rchild;
    return temp;
}

Node *erase_maintain(Node *root) {
    if (root->lchild->color != DOUBLE_BLACK && root->rchild->color != DOUBLE_BLACK) return root;
    if (root->lchild->color == DOUBLE_BLACK) {
        if (root->rchild->color == RED) {
            root = left_rotate(root);
            root->color = BLACK;
            root->lchild->color = RED;
            root->lchild = erase_maintain(root->lchild);
            return root;
        }
        if (!hasRedChild(root->rchild)) {
            root->color += 1;
            root->lchild->color -= 1;
            root->rchild->color -= 1;
            return root;
        }
        if (root->rchild->lchild->color == RED) {
            root->rchild = right_rotate(root->rchild);
            root->rchild->color = BLACK;
            root->rchild->rchild->color = RED;
        }
        root = left_rotate(root);
        root->color = root->lchild->color;
        root->lchild->color = root->rchild->color = BLACK;
        root->lchild->lchild->color -= 1;
    } else {
        if (root->lchild->color == RED) {
            root = right_rotate(root);
            root->color = BLACK;
            root->rchild->color = RED;
            root->rchild = erase_maintain(root->rchild);
            return root;
        }
        if (!hasRedChild(root->lchild)) {
            root->color += 1;
            root->lchild->color -= 1;
            root->rchild->color -= 1;
            return root;
        }
        if (root->lchild->rchild == RED) {
            root->lchild = left_rotate(root->lchild);
            root->lchild->color = BLACK;
            root->lchild->lchild->color = RED;
        }
        root = right_rotate(root);
        root->color = root->rchild->color;
        root->lchild->color = root->rchild->color = BLACK;
        root->rchild->rchild->color -= 1;
    }
    return root;
}

Node *_erase(Node *root, int value) {
    if (root == NIL) return root;
    if (root->value < value) root->rchild = _erase(root->rchild, value);
    else if (root->value > value) root->lchild = _erase(root->lchild, value);
    else {
        if (root->lchild == NIL || root->rchild == NIL) {
            Node *temp = root->lchild == NIL ? root->rchild : root->lchild;
            temp->color += root->color;
            free(root);
            return temp;
        }
        Node *temp = predecessor(root);
        root->value = temp->value;
        root->lchild = _erase(root->lchild, temp->value);
    }
    return erase_maintain(root);
}

Node *erase(Node *root, int value) {
    root = _erase(root, value);
    root->color = BLACK;
    return root;
}

void clear(Node *root) {
    if (root == NIL) return ;
    clear(root->lchild);
    clear(root->rchild);
    free(root);
}

void output(Node *root) {
    if (root == NIL) return ;
    printf("%d[%d, %d]\n", root->value, root->lchild->value, root->rchild->value);
    output(root->lchild);
    output(root->rchild);
}

int main() {
    Node *root = NIL;
    for (int i = 10; i >= 1; i--) {
        root = insert(root, i);
    }
    for (int i = 10; i >= 5; i--) {
        root = erase(root, i); 
        output(root);
        printf("\n");
    }
    return 0;
}
