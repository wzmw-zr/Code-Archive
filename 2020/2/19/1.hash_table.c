/*************************************************************************
	> File Name: 1.hash_table.c
	> Author:赵睿 
	> Mail: 1767153298@qq.com
	> Created Time: 2020年02月19日 星期三 09时33分43秒
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>

typedef struct node {
    char *str;
    struct node *next;
} Node;

typedef struct hashtable {
    Node **data;
    int size;
} HashTable;

Node *init_node(char *str, Node *head) {
    Node *p = (Node *) malloc(sizeof(Node));
    p->str = strdup(str);
    p->next = head;
    return p;
}

HashTable *init_hashtable(int n) {
    HashTable *h = (HashTable *) malloc(sizeof(HashTable));
    h->size = n << 1;
    h->data = (Node **) calloc(sizeof(Node *), h->size);
    return h;
}

int BKDRHash(char *str) {
    int seed = 31, hash = 0;
    for (int i = 0; str[i]; i++) hash = hash * seed + str[i];
    return hash & 0x7fffffff;
}

int insert(HashTable *h, char *str) {
    int hash = BKDRHash(str);
    int ind = hash % h->size;
    h->data[ind] = init_node(str, h->data[ind]);
    return 1;
}

int search(HashTable *h, char *str) {
    int hash = BKDRHash(str);
    int ind = hash % h->size;
    Node *p = h->data[ind];
    while (p && strcmp(p->str, str)) p = p->next;
    return p != NULL;
}

void clear_node(Node *node) {
    if (!node) return ;
    Node *p = node , *q;
    while (p) {
        q = p->next;
        free(p->str);
        free(p);
        p = q;
    }
}

void clear_hashtable(HashTable *h) {
    if (!h) return ;
    for (int i = 0; i < h->size; i++) clear_node(h->data[i]);
    free(h->data);
    free(h);
}

int main() {
    #define max_n 100
    char str[max_n + 5];
    int op;
    HashTable *h = init_hashtable(max_n + 5);
    while (~scanf("%d%s", &op, str)) {
        switch (op) {
            case 0: {
                printf("insert %s to hash table\n", str);
                insert(h, str);
            } break;
            case 1: {
                printf("search %s result = %d\n", str, search(h, str));
            } break;
        }
    }
    clear_hashtable(h);
    return 0;
}
