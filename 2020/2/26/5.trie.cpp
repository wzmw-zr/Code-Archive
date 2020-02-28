/*************************************************************************
	> File Name: 5.trie.cpp
	> Author:赵睿 
	> Mail: 1767153298@qq.com
	> Created Time: 2020年02月26日 星期三 19时41分58秒
 ************************************************************************/

#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
using namespace std;
#define BASE 26
#define BASE_LETTER 'a'

typedef struct Node {
    int flag;
    struct Node *next[26];
} Node;

Node *getNewNode() {
    Node *p = (Node *) calloc(sizeof(Node), 1);
    return p;
}

void clear(Node *root) {
    if (!root) return ;
    for (int i = 0; i < BASE; i++) clear(root->next[i]);
    clear(root);
    return ;
}

inline int code(char ch) {
    return ch - BASE_LETTER;
}

void insert(Node *root, char *str) {
    Node *p = root;
    for (int i = 0; str[i]; i++) {
        if (p->next[code(str[i])] == NULL) p->next[code(str[i])] = getNewNode();
        p = p->next[code(str[i])];
    }
    p->flag = 1;
    return ;
}

int query(Node *root, char *str) {
    Node *p = root;
    for (int i = 0; str[i]; i++) {
        p = p->next[code(str[i])];
        if (!p) return 0;
    }
    return p->flag;
}

void output(Node *root, int k, char *buffer) {
    if (!root) return ;
    if (root->flag) printf("%s\n", buffer);
    for (int i = 0; i < BASE; i++) {
        buffer[k] = BASE_LETTER + i;
        buffer[k + 1] = '\0';
        output(root->next[i], k + 1, buffer);
    }
}

int main() {
    char str[1000];
    int n;
    scanf("%d", &n);
    Node *root = getNewNode();
    for (int i = 0; i < n; i++) {
        scanf("%s", str);
        insert(root, str);
    }
    output(root, 0, str);
    while (~scanf("%s", str)) {
        printf("query %s, result = %s\n", str, query(root, str) ? "Yes" : "No");
    }
    return 0;
}

