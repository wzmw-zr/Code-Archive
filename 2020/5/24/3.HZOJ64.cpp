/*************************************************************************
	> File Name: 3.HZOJ64.cpp
	> Author:赵睿 
	> Mail: 1767153298@qq.com
	> Created Time: 2020年05月24日 星期日 18时33分16秒
 ************************************************************************/

#include<iostream>
#include<cstdlib>
#include<cstring>
#include<algorithm>
using namespace std;
#define RED 0
#define BLACK 1
#define DBLACK 2
#define L(x) (x->lchild)
#define R(x) (x->rchild)
#define COLOR(x) (x->color)

struct Node {
    int key, color;
    struct Node *lchild, *rchild;
};

Node _NIL, *NIL = &(_NIL);
__attribute__((constructor))
void init() {
    NIL->color = BLACK;
    NIL->lchild = NIL, NIL->rchild = NIL;
}

Node *GetNewNode(int key) {
    Node *p = (Node *) calloc(sizeof(Node), 1);
    p->key = key;
    p->color = RED;
    p->lchild = p->rchild = NIL;
    return p;
}

bool HasRedChild(Node *root) {
    return root->lchild == RED || root->rchild == RED;
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
    return root;
}

Node *insert_maintain(Node *root) {
    if (!HasRedChild(root)) return root;
    if (!HasRedChild(L(root)) && !HasRedChild(R(root))) return root;
    if (L(root)->color == RED && R(root)->color == RED) {
        L(root)->color = R(root)->color = BLACK;
        root->color = RED;
        return root;
    } 
    if (L(root)->color == RED) {
        if (R(L(root))->color == RED) root->lchild = left_rotate(root->lchild);
        root = right_rotate(root);
    } else {
        if (L(R(root))->color == RED) root->rchild = left_rotate(root->rchild);
        root = left_rotate(root);
    }
    root->lchild->color = root->rchild->color = BLACK;
    return root;
}

Node *_insert(Node *root, int key) {
    if (root == NIL) return GetNewNode(key);
    if (root->key == key) return root;
    if (root->key > key) root->lchild = _insert(root->lchild, key);
    else root->rchild = _insert(root->rchild, key);
    return insert_maintain(root);
}

Node *insert(Node *root, int key) {
    root = _insert(root, key);
    root->color = BLACK;
    return root;
}

Node *predecessor(Node *root) {
    Node *temp = root->lchild;
    while (temp->rchild) temp = temp->rchild;
    return temp;
}

Node *erase_maintain(Node *root) {
    if (root->lchild->color == DBLACK) {
        if (root->rchild->color == BLACK) {
            if (!HasRedChild(root->rchild)) {
                root->color += 1, root->lchild->color -= 1, root->rchild->color -= 1;
            } else {
                if (COLOR(L(R(root))) == RED) {
                    R(root)->color = RED;
                    R(root) = right_rotate(R(root));
                    R(root)->color = BLACK;
                }
                COLOR(R(root)) = COLOR(root);
                root->color = BLACK;
                root = left_rotate(root);
                COLOR(R(root)) = BLACK;
            }
        } else {
            root->color = RED;
            root = left_rotate(root);
            root->color = BLACK;
            root->lchild = erase_maintain(root->lchild);
        }
    } else { 
        if (root->lchild->color == BLACK) {
            if (!HasRedChild(root->lchild)) {
                root->color += 1, root->rchild->color -= 1, root->lchild->color -= 1;
            } else {
                if (COLOR(R(L(root))) == RED) {
                    L(root)->color = RED;
                    L(root) = left_rotate(L(root));
                    L(root)->color = BLACK;
                }
                COLOR(L(root)) = COLOR(root);
                root->color = BLACK;
                root = right_rotate(root);
                COLOR(L(root)) = BLACK;
            }
        } else {
            root->color = RED;
            root = right_rotate(root);
            root->color = BLACK;
            root->rchild = erase_maintain(root->rchild);
        }
    }
    return root;
}

Node *_erase(Node *root, int key) {
    if (root == NIL) return root;
    if (root->key < key) root->rchild = _erase(root->rchild, key); 
    else if (root->key > key) root->lchild = _erase(root->lchild, key);
    else {
        if (root->lchild == NIL || root->rchild == NIL) {
            Node *temp = root->lchild == NIL ? root->rchild : root->lchild;
            free(root);
            temp->color += 1;
            return temp;
        }
        Node *temp = predecessor(root);
        root->key = temp->key;
        root->lchild = _erase(root->lchild, temp->key);
    }
    return erase_maintain(root);
}

Node *erase(Node *root, int key) {
    root = _erase(root, key);
    root->color = BLACK;
    return root;
}

void erase(Node *root) {
    if (root == NIL) return ;
    erase(root->lchild);
    erase(root->rchild);
    free(root);
}

int main() {
    return 0;
}
