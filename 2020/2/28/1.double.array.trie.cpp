/*************************************************************************
	> File Name: 1.double.array.trie.cpp
	> Author:赵睿 
	> Mail: 1767153298@qq.com
	> Created Time: 2020年02月28日 星期五 09时04分22秒
 ************************************************************************/

#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<ctime>
using namespace std;
#define BASE 26
#define BEGIN_LETTER 'a'

typedef struct Node {
    int flag;
    struct Node *next[BASE];
} Node;

typedef struct DATrie {
    int *base, *check;
    int root, size;
} DATrie;

DATrie *getNewDATrie(int n) {
    DATrie *p = (DATrie *) calloc(sizeof(DATrie), 1);
    p->root = 1;
    p->size = n;
    p->base = (int *) calloc(sizeof(int), n);
    p->check = (int *) calloc(sizeof(int), n);
    p->check[p->root] = -1;
    return p;
}

Node *getNewNode() {
    Node *p = (Node *) calloc(sizeof(Node), 1);
    return p;
}

void insert(Node *root, const char *str) {
    Node *p = root;
    for (int i = 0; str[i]; i++) {
        int ind = str[i] - BEGIN_LETTER;
        if (!p->next[ind]) p->next[ind] = getNewNode();
        p = p->next[ind];
    }
    p->flag = 1;
}

void clear(Node *root) {
    if (!root) return ;
    for (int i = 0; i < BASE; i++) clear(root->next[i]);
    free(root);
}

int getBaseValue(Node *root, DATrie *tree) {
    int base = 1, flag = 1;
    do {
        flag = 1;
        base += 1;
        for (int i = 0; i < BASE; i++) {
            if (!root->next[i]) continue;
            if (!tree->check[base + i]) continue;
            flag = 0;
            break;
        }
    } while (!flag);
    return base;
}

void buildDATrie(int ind, Node *root, DATrie *tree) {
    int base = tree->base[ind] = getBaseValue(root, tree);
    for (int i = 0; i < BASE; i++) {
        if (!root->next[i]) continue;
        tree->check[base + i] = ind;
    }
    for (int i = 0; i < BASE; i++) {
        if (!root->next[i]) continue;
        buildDATrie(base + i, root, tree);
    }
    if (root->flag) tree->check[ind] = -tree->check[ind];
}

void clearDATrie(DATrie *tree) {
    if (!tree) return ;
    free(tree->base);
    free(tree->check);
    free(tree);
}

int main() {

    return 0;
}
