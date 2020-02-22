/*************************************************************************
	> File Name: 2.hashtable.cpp
	> Author:赵睿 
	> Mail: 1767153298@qq.com
	> Created Time: 2020年02月22日 星期六 15时02分21秒
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<string.h>


typedef struct node {
    char *str;
    struct node *next;
} Node;

typedef struct HashTable {
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

void clear_node(Node *head) {
    if (!head) return ;
    Node *p = head, *q;
    while (!p) {
        q = p->next;
        free(p->str);
        free(p);
        p = q;
    }
}

void clear_hashtable(HashTable *h) {
    if (!h) return;
    for (int i = 0; i < h->size; i++) clear_node(h->data[i]);
    free(h->data);
    free(h);
}

int BKDRHash(char *str) {
    int seed = 31, hash = 0;
    for (int i = 0; str[i]; i++) hash = hash * seed + str[i];
    return hash & 0x7fffffff;
}

int insert(HashTable *h, char *str) {
    int ind = BKDRHash(str) % h->size;
    h->data[ind] = init_node(str, h->data[ind]);
    return 1;
}

int search(HashTable *h, char *str) {
    int ind = BKDRHash(str) % h->size;
    Node *p = h->data[ind];
    while (p && strcmp(p->str, str)) p = p->next;
    return p != NULL;
}

int main() {
    srand(time(0));
    #define max_n 100
    int op;
    char str[max_n + 5];
    HashTable *h = init_hashtable(max_n + 5);
    while (~scanf("%d %s", &op, str)) {
        switch (op) {
            case 0 : {
                printf("insert %s to HashTable\n", str);
                insert(h, str);
            } break; 
            case 1 : {
                printf("search %s from HashTable = %d\n", str, search(h, str));
            } break;
        }
    }
    clear_hashtable(h);
    return 0;
}
