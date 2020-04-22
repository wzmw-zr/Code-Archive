/*************************************************************************
	> File Name: 2.BST.cpp
	> Author:赵睿 
	> Mail: 1767153298@qq.com
	> Created Time: 2020年04月21日 星期二 19时26分11秒
 ************************************************************************/

#include<cstdlib>
#include<cstring>
#include<cstdio>
#include<ctime>
using namespace std;

typedef struct Node {
    int key;
    struct Node *lchild, *rchild;
} Node;

Node *getNewNode(int key) {
    Node *node = (Node *) calloc(sizeof(Node), 1);
    node->key = key;
    return node;
}

Node *insert(Node *root, int key) {
    if (!root) return getNewNode(key);
    if (root->key == key) return root;
    if (root->key > key) root->lchild = insert(root->lchild, key);
    else root->rchild = insert(root->rchild, key);
    return root;
}

Node *predessor(Node *root) {
    Node *temp = root->lchild;
    while (temp->rchild) temp = temp->rchild;
    return temp;
}

Node *erase(Node *root, int key) {
    if (!root) return root;
    if (root->key > key) root->lchild = erase(root->lchild, key);
    else if (root->key < key) root->rchild = erase(root->rchild, key);
    else {
        if (!root->lchild || !root->rchild) {
            Node *temp = root->lchild ? root->lchild : root->rchild;
            free(root);
            return temp;
        } else {
            Node *temp = predessor(root);
            root->key = temp->key;
            root->lchild = erase(root->lchild, temp->key);
        }
    }
    return root;
}

void clear(Node *root) {
    if (!root) return ;
    clear(root->lchild);
    clear(root->rchild);
    free(root);
}

void output(Node *root) {
    if (!root) return ;
    output(root->lchild);
    printf("%d ", root->key);
    output(root->rchild);
}

int main() {
    srand(time(0));
    #define MAX_OP 30
    Node *root = NULL;
    for (int i = 0; i < MAX_OP; i++) {
        int op = rand() % 5, val = rand() % 20;
        switch (op) {
            case 2:
            case 3:
            case 4:
            case 0 : {
                printf("Insert %d to binary search tree\n", val);
                root = insert(root, val);
            } break;
            case 1 : {
                printf("erase %d from binary search tree\n", val);
                root = erase(root, val);
            } break;
        }
        output(root);
        printf("\n");
    }
    return 0;
}
