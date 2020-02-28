/*************************************************************************
	> File Name: 2.trie.cpp
	> Author:赵睿 
	> Mail: 1767153298@qq.com
	> Created Time: 2020年02月27日 星期四 22时19分49秒
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
    struct Node *next[BASE];
} Node;

Node *getNewNode() {
    Node *p = (Node *) calloc(sizeof(Node), 1);
    return p;
}

inline int code(char ch) {
    return ch - BASE_LETTER;
}

void insert(Node *root, char *str) {
    Node *p = root;
    for (int i = 0; str[i]; i++) {
        if (!p->next[code(str[i])]) p->next[code(str[i])] = getNewNode();
        p = p->next[code(str[i])];
    }
    p->flag = 1;
}

int query(Node *root, char *str) {
    if (!root) return 0;
    Node *p = root;
    for (int i = 0; str[i]; i++) {
        p = p->next[code(str[i])];
        if (!p) return 0;
    }
    return p->flag;
}

void clear(Node *root) {
    if (!root) return ;
    for (int i = 0; i < BASE; i++) clear(root->next[i]);
    free(root);
}

void output(Node *root, int k, char *buffer) {
    if (!root) return ;
    if (root->flag) {
        printf("%s\n", buffer);
    }
    for (int i = 0; i < BASE; i++) {
        buffer[k] = BASE_LETTER + i;
        buffer[k + 1] = '\0';
        output(root->next[i], k + 1, buffer);
    }
}

int main() {
    char str[100], buffer[100];
    int n;
    Node *root = getNewNode();
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%s", str);
        insert(root, str);
    }
    output(root, 0, buffer);
    while (~scanf("%s", str)) {
        printf("query %s, result = %s\n", str, query(root, str) ? "Yes" : "No");
    }
    return 0;
}
