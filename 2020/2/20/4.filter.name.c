/*************************************************************************
	> File Name: 4.filter.name.c
	> Author:赵睿 
	> Mail: 1767153298@qq.com
	> Created Time: 2020年02月20日 星期四 17时42分59秒
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define max_l 100
#define max_n 100000

typedef struct node {
    char name[max_l + 5];
    struct node *next;
} Node;

typedef struct HashTable {
    Node **data;
    int size;
} HashTable;

Node *NewNode(char *name) {
    Node *node = (Node *) malloc(sizeof(Node));
    strcpy(node->name, name);
    node->next = NULL;
    return node;
}

HashTable *NewHashTable(int n) {
    HashTable *h = (HashTable *) malloc(sizeof(HashTable));
    h->data = (Node **) calloc(sizeof(Node *), max_n);
    h->size = n;
    return h;
}

void clearNode(Node *node) {
    if (!node) return ;
    free(node);
}

void clearHashTable(HashTable *h) {
    if (!h) return ;
    for (int i = 0; i < max_n; i++) {
        if (!h->data[i]) continue;
        free(h->data[i]);
    }
    free(h);
}

Node *insert(Node *head, Node *node) {
    if (!head) {
        head = node;
        return head;
    }
    node->next = head;
    head = node;
    return head;
}

int hash(char *name) {
    int ret = 0, seed = 131313;
    for (int i = 0; name[i]; i++) {
        ret  = ret * seed + name[i];
    }
    return ret & 0x7fffffff;
}

void change(char *name) {
    for (int i = 0; name[i]; i++) {
        if (name[i] >= 'A' && name[i] <= 'Z') name[i] += 32;
    }
}

int exist_same(HashTable *h, int data, char *name) {
    if (!h->data[data % h->size]) return 0;
    Node *node = h->data[data % h->size];
    while (node && strcmp(name, node->name)) {
        node = node->next;
    }
    if (!node) return 0;
    return 1;
}


int main() {
    int n;
    scanf("%d", &n);
    HashTable *h = NewHashTable(n);
    for (int i = 0; i < n; i++) {
        char name[100] = {0};
        scanf("%s", name);
        change(name);
        int data = hash(name) % n;
        if (exist_same(h, data, name)) printf("Yes\n");
        else {
            printf("No\n");
            h->data[data % n] = insert(h->data[data % n], NewNode(name));
        }
    }    
    return 0;
}
