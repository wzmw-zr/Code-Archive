/*************************************************************************
	> File Name: 1.RBTree.cpp
	> Author:赵睿 
	> Mail: 1767153298@qq.com
	> Created Time: 2020年05月16日 星期六 14时25分19秒
 ************************************************************************/

#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<ctime>
using namespace std;

#define RED 0
#define BLACK 1
#define DBLACK 2

typedef struct Node {
    int key, color;
    struct Node *lchild, *rchild;
} Node;

Node __NIL;
#define NIL (&__NIL)

__attribute__((constructor))
void init_NIL() {
    NIL->key = 0;
    NIL->color = BLACK;
    NIL->lchild = NIL->rchild = NIL;
}

Node *getNewNode(int key) {
    Node *p = (Node *) calloc(sizeof(Node), 1);
    p->key = key;
    p->color = RED;
    p->lchild = p->rchild = NIL;
    return p;
}

bool has_red_child(Node *root) {
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
    if (!has_red_child(root)) return root;
    if (root->lchild->color == RED && root->rchild->color == RED) {
        root->color = RED;
        root->lchild->color = root->rchild->color = BLACK;
        return root;
    }
    if (root->lchild->color == RED) {
        if (!has_red_child(root->lchild)) return root;
        if (root->lchild->rchild == RED) {
            root->lchild = left_rotate(root->lchild);
        }
        root = right_rotate(root);
    } else {
        if (!has_red_child(root->rchild)) return root;
        if (root->rchild->lchild->color == RED) {
            root->rchild = right_rotate(root->rchild);
        }
        root = left_rotate(root);
    }
    root->color = RED;
    root->lchild->color = root->rchild->color = BLACK;
    return root;
}

Node *predecessor(Node *root) {
    Node *temp = root->lchild;
    if (temp->rchild != NIL) temp = temp->rchild;
    return temp;
}

Node *erase_maintain(Node *root) {
    if (root->lchild->color != DBLACK && root->rchild->color != DBLACK) 
        return root;
    if (has_red_child(root)) {
        root->color = RED;
        if (root->lchild->color == RED) {
            root = right_rotate(root);
            root->rchild = erase_maintain(root->rchild);
        } else {
            root = left_rotate(root);
            root->lchild = erase_maintain(root->lchild);
        }
        root->color = BLACK;
        return root;
    }
    if ((root->lchild->color == DBLACK && !has_red_child(root->rchild)) || (root->rchild->color == DBLACK && !has_red_child(root->lchild))) {
        root->color += 1;
        root->lchild->color -= 1;
        root->rchild->color -= 1; 
        return root;
    }
    if (root->rchild->color == BLACK) {
        if (root->rchild->rchild->color != RED) {
            root->rchild->color = RED;
            root->rchild = right_rotate(root->rchild);
            root->rchild->color = BLACK;
        }
        root->rchild->color = root->color;
        root->color = BLACK;
        root->lchild->color -= 1;
        root = left_rotate(root);
        root->rchild->color = BLACK;
    } else { 
        if (root->lchild->lchild->color != RED) {
            root->lchild->color = RED;
            root->lchild = left_rotate(root->lchild);
            root->lchild->color = BLACK;
        }
        root->lchild->color = root->color;
        root->color = BLACK;
        root->rchild->color -= 1;
        root = right_rotate(root);
        root->lchild->color = BLACK;
    }
    return root;
}

Node *__erase(Node *root, int key) {
    if (root == NIL) return root;
    if (root->key > key) root->lchild = __erase(root->lchild, key);
    else if (root->key < key) root->rchild = __erase(root->rchild, key);
    else {
        if (root->lchild == NIL || root->rchild == NIL) {
            Node *temp = root->lchild == NIL ? root->rchild : root->lchild;
            temp->color += root->color;
            free(root);
            return temp;
        } else {
            Node *temp = predecessor(root);
            root->key = temp->key;
            root->lchild = __erase(root->lchild, temp->key);
        }
    }
    return erase_maintain(root);
}

Node *erase(Node *root, int key) {
    root = __erase(root, key);
    root->color = BLACK;
    return root;
}

Node *__insert(Node *root, int key) {
    if (root == NIL) return getNewNode(key);
    if (root->key == key) return root;
    if (root->key > key) root->lchild = __insert(root->lchild, key);
    else root->rchild = __insert(root->rchild, key);
    return insert_maintain(root);
}

Node *insert(Node *root, int key) {
    root = __insert(root, key);
    root->color = BLACK;
    return root;
}



void output(Node *root) {
    if (root == NIL) return ;
    printf("(%d | %d, %d, %d)\n", 
        root->color,
        root->key,
        root->lchild->key,
        root->rchild->key
    );
    output(root->lchild);
    output(root->rchild);
}

void clear(Node *root) {
    if (root == NIL) return ;
    clear(root->lchild);
    clear(root->rchild);
    free(root);
}

int main() {
    int op, val;
    Node *root = NIL;
    while (~scanf("%d%d", &op, &val)) {
        switch (op) {
            case 0 : root = insert(root, val); break;
            case 1: root = erase(root, val); break;
        }  
        output(root);
    }
    return 0;
}
