/*************************************************************************
	> File Name: 5.38.appearance.array.cpp
	> Author:赵睿 
	> Mail: 1767153298@qq.com
	> Created Time: 2020年02月23日 星期日 14时19分55秒
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct Node {
    char c;
    int cnt;
} Node;

typedef struct HashTable {
    Node **data;
    int size;
} HashTable;

Node *NewNode(char val, int cnt) {
    Node *p = (Node *) malloc(sizeof(Node));
    p->c = val;
    p->cnt = cnt;
    return p;
}

HashTable *NewHashTable(int size) {
    HashTable *h = (HashTable *) malloc(sizeof(HashTable));
    h->data = (Node **) malloc(sizeof(Node *) * (size + 1));
    h->size = size; 
    return h;
}

void insert(HashTable *h, int ind, char val, int cnt) {
    if (!h) return ;
    h->data[ind] = NewNode(val, cnt);
}

void clearNode(Node *p) {
    if (!p) return ;
    free(p);
}

void clearHashTable(HashTable *h) {
    if (!h) return ;
    for (int i = 0; i <= h->size; i++) {
        if (!h->data[i]) continue;
        clearNode(h->data[i]);
    }
    free(h->data);
    free(h);
}

char *get_array(HashTable *h) {
    char *ret = (char *) calloc(sizeof(char), 2 * h->size);
    int cnt = 0;
    for (int i = 0; i < h->size; i++) {
        if (!h->data[i]) continue;
        printf("c = %c, cnt = %d\n", h->data[i]->c, h->data[i]->cnt);
        ret[cnt++] = h->data[i]->cnt + '0';
        ret[cnt++] = h->data[i]->c;
    }
    return ret;
}

HashTable *get_hashtable(int size, char *num) {
    HashTable *h = NewHashTable(size);
    int cnt = 0, ind = 0;
    char c;
    for (int i = 0; num[i]; i++) {
        printf("%c", num[i]);
        if (!i) {
            c = num[i];
            cnt++;
        } else {
            if (num[i] == c) {
                cnt++;
            } else {
                insert(h, ind++, c, cnt);
                c = num[i];
                cnt = 1;
            }
        }
    }
    printf("\n");
    return h;
}

char * countAndSay(int n){
    HashTable *h = NewHashTable(1); 
    h->data[0] = NewNode('1', 1);
    char *num;
    for (int i = 1; i <= n; i++) {
        num = get_array(h);
        //for (int i = 0; num[i]; i++) printf("%c", num[i]);
        //printf("\n");
        HashTable *next = get_hashtable((h->size) << 1, num);
        clearHashTable(h);
        h = next;
    }
    return num;
}

int main() {
    int n;
    scanf("%d", &n);
    char *s = countAndSay(n);
    for (int i = 0; s[i]; i++) printf("%c", s[i]);
    printf("\n");
    return 0;
}
