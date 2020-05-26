/*************************************************************************
	> File Name: 1.RBTree.cpp
	> Author:赵睿 
	> Mail: 1767153298@qq.com
	> Created Time: 2020年05月26日 星期二 15时37分31秒
 ************************************************************************/

#include<iostream>
#include<cstdlib>
#include<cstring>
using namespace std;
#define RED 0
#define BLACK 1
#define DBLACK 2

struct Node {
    int key, color;
    struct Node *lchild, *rchild;
};

Node _NIL, *NIL = &(_NIL);
__attribute__((constructor))
void init() {
    NIL->key = 0;
    NIL->color = BLACK;
    NIL->lchild = NIL->rchild = NIL;
}

Node *GetNewNode(int key) {
    Node *p = (Node *) calloc(sizeof(Node), 1);
    p->color = RED;
    p->key = key;
    p->lchild = p->rchild = NIL;
    return p;
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

int HasRedChild(Node *root) {
    return root->lchild->color == RED || root->rchild->color == RED;
}

Node *insert_maintain(Node *root) {
    if (!HasRedChild(root)) return root;
    if (root->lchild->color == RED && root->rchild->color == RED) {
        if (!HasRedChild(root->lchild) && !HasRedChild(root->rchild))
            return root;
        root->lchild->color = root->rchild->color = BLACK;
        root->color = RED;
        return root;
    }
    if (root->lchild->color == RED) {
        if (!HasRedChild(root->lchild)) return root;
        if (root->lchild->rchild->color == RED) {
            root->lchild = left_rotate(root->lchild);
        }
        root = right_rotate(root);
        root->lchild->color = BLACK;
    } else {
        if (!HasRedChild(root->rchild)) return root;
        if (root->rchild->lchild->color == RED) {
            root->rchild = right_rotate(root->rchild);
        }
        root = left_rotate(root);
        root->rchild->color = BLACK;
    }
    return root;
}

Node *_insert(Node *root, int key) {
    if (root == NIL) return GetNewNode(key);
    if (root->key == key) return root;
    if (root->key < key) root->rchild = _insert(root->rchild, key);
    else root->lchild = _insert(root->lchild, key);
    return insert_maintain(root);
}

Node *insert(Node *root, int key) {
    root = _insert(root, key);
    root->color = BLACK;
    return root;
}

Node *predecessor(Node *root) {
    Node *temp = root->lchild;
    while (temp->rchild != NIL) temp = temp->rchild;
    return temp;
}

Node *erase_maintain(Node *root) {
    if (root->lchild->color != DBLACK && root->rchild->color != DBLACK) 
        return root;
    if (root->lchild->color == DBLACK) {
        if (root->rchild->color == RED) {
            root->color = RED;
            root = left_rotate(root);
            root->color = BLACK;
            root->lchild = erase_maintain(root->lchild);
        } else {
            if (!HasRedChild(root->rchild)) {
                root->color += 1;
                root->lchild->color -= 1;
                root->rchild->color -= 1;
                return root;
            }
            if (root->rchild->rchild->color == RED) {}
            else {
                root->rchild->color = RED;
                root->rchild = right_rotate(root->rchild); 
                root->rchild->color = BLACK;
            }
            root->rchild->color = root->color;
            root->color = BLACK;
            root = left_rotate(root);
            root->lchild->lchild->color -= 1;
            root->rchild->color += 1;
        }
    } else { 
        if (root->lchild->color == RED) {
            root->color = RED;
            root = right_rotate(root);
            root->color = BLACK;
            root->rchild = erase_maintain(root->rchild);
        } else {
            if (!HasRedChild(root->lchild)) {
                root->color += 1;
                root->rchild->color -= 1;
                root->lchild->color -= 1;
                return root;
            }
            if (root->lchild->lchild->color == RED) {}
            else {
                root->lchild->color = RED;
                root->lchild = left_rotate(root->lchild); 
                root->lchild->color = BLACK;
            }
            root->lchild->color = root->color;
            root->color = BLACK;
            root = right_rotate(root);
            root->rchild->rchild->color -= 1;
            root->lchild->color += 1;
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
            temp->color += root->color;
            free(root);
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

void clear(Node *root) {
    if (root == NIL) return ;
    clear(root->lchild);
    clear(root->rchild);
    free(root);
}

void output(Node *root) {
    if (root == NIL) return ;
    output(root->lchild);
    cout << root->key << " " << root->color << " " << root->lchild->key << " " << root->rchild->key << endl;
    output(root->rchild);
}

int main() {
    Node *root = NIL;
    int x, y;
    while ((cin >> x >> y)) {
        switch (x) {
            case 1 : root = insert(root, y); break;
            case 2 : root = erase(root, y); break;
            case 3 : output(root); break;
        }
    }
    clear(root);
    return 0;
}
