/*************************************************************************
	> File Name: 6.double_array_trie.cpp
	> Author:赵睿 
	> Mail: 1767153298@qq.com
	> Created Time: 2020年02月26日 星期三 21时53分53秒
 ************************************************************************/

#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<ctime>
#include<cmath>
using namespace std;
#define BASE 26
#define BEGIN_LETTER 'a'

typedef struct Node {
    int flag;
    struct Node *next[BASE];
} Node;

typedef struct DATrie {
    int *base , *check;
    int root, size;
} DATrie;

DATrie *getDATrie(int n) {
    DATrie *tree = (DATrie *) calloc(sizeof(DATrie), 1);
    tree->root = 1;
    tree->size = n;
    tree->base = (int *) calloc(sizeof(int), n);
    tree->check = (int *) calloc(sizeof(int), n);
    tree->check[tree->root] = 1;
    return tree;
}

Node *getNewNode() {
    Node *p = (Node *) calloc(sizeof(Node), 1);
    return p;
}

int insert(Node *root, const char *str) {
    int cnt = 1;
    Node *p = root;
    for (int i = 0; str[i]; i++) {
        int ind = str[i] - BEGIN_LETTER;
        if (p->next[ind] == NULL) p->next[ind] = getNewNode(), cnt += 1;
        p = p->next[ind];
    }
    p->flag = 1;
    return cnt;
}

void clear(Node *root) {
    if (!root) return ;
    for (int i = 0; i < BASE; i++) clear(root->next[i]);
    free(root);
}

int getBaseValue(Node *root, DATrie *tree) {
    int base = 1, flag;
    do {
        flag = 1;
        base += 1;
        for (int i = 0; i < BASE; i++) {
            if (root->next[i] == NULL) continue;
            if (tree->check[base + i] == 0) continue;
            flag = 0;
            break;
        }
    } while (!flag);
    return base;
}

void build_DATrie(int ind, Node *root, DATrie *tree) {
    int base = tree->base[ind] = getBaseValue(root, tree);
    for (int i; i < BASE; i++) {
        if (root->next[i] == NULL) continue ;
        tree->check[base + i] = ind;
    }
    for (int i = 0; i < BASE; i++) {
        if (root->next[i] == NULL) continue;
        build_DATrie(base + i, root->next[i], tree);
    }
    if (root->flag) tree->check[ind] = -tree->check[ind];
}

void clearDA(DATrie *tree) {
    if (!tree) return ;
    free(tree->base);
    free(tree->check);
    free(tree);
    return ;
}

int query(DATrie *tree, const char *str) {
    int p = tree->root;
    for (int i = 0; str[i]; i++) {
        int ind = str[i] - BEGIN_LETTER;
        if (abs(tree->check[tree->base[p] + ind]) != p) return 0;
        p = tree->base[p] + ind;
    }
    return tree->check[p] < 0;
}

int main() {
    int n, cnt = 0;
    char str[100];
    Node *root = getNewNode();
    scanf("%d", &n);
    while (n--) {
        scanf("%s", str);
        cnt += insert(root, str);
    }
    DATrie *tree = getDATrie(cnt * BASE + 5);
    build_DATrie(tree->root, root, tree);
    while (!scanf("%s", str)) {
        printf("search %s, result = %s\n", str, query(tree, str) ? "Yes" : "No");
    }
    clearDA(tree);
    clear(root);
    return 0;
}
