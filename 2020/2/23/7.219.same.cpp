/*************************************************************************
	> File Name: 7.219.same.cpp
	> Author:赵睿 
	> Mail: 1767153298@qq.com
	> Created Time: 2020年02月23日 星期日 16时53分37秒
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<inttypes.h>


typedef struct Node {
    int ind, val;
    struct Node *next;
} Node;

typedef struct HashTable {
    Node **data;
    int size;
} HashTable;

Node *initNode(int ind, int val) {
    Node *p = (Node *) malloc(sizeof(Node));
    p->ind = ind;
    p->val = val;
    p->next = NULL;
    return p;
}

HashTable *initHashTable(int size) {
    HashTable *h = (HashTable *) malloc(sizeof(HashTable));
    h->data = (Node **) calloc(sizeof(Node *), size << 1);
    h->size = size;
    return h;
}

int find(HashTable *h, int ind, int val, int k) {
    int temp = val & 0x7ffffff;
    if (!h->data[temp % h->size]) return -1;
    Node *head = h->data[temp % h->size];
    int min = INT32_MAX;
    while (head) {
        if (head->val == val && head->ind < min) {
            if (ind - head->ind == k) return -2;
            min = head->ind;
        }
        head = head->next;
    }
    if (min != INT32_MAX) return min;
    return -1;
}

void insert(HashTable *h, int ind, int val) {
    int temp = val & 0x7fffffff;
    Node *p = initNode(ind, val);
    p->next = h->data[temp % h->size];
    h->data[temp % h->size] = p;
}

void update(HashTable *h, int max, int val) {
    int temp = val & 0x7fffffff;
    Node *p = h->data[temp % h->size];
    while (p && p->val != val) p = p->next;
    if (p) p->ind = max;
    else insert(h, max, val); 
}

bool containsNearbyDuplicate(int* nums, int numsSize, int k){
    HashTable *h1 = initHashTable(numsSize), *h2 = initHashTable(numsSize);
    for (int i = 0; i < numsSize; i++) {
        int ind = find(h1, i, nums[i], k);
        if (ind == -1) insert(h1, i, nums[i]);
        else if (ind == -2) return true;
        else {
            int max = i - ind;
            if (max == k) return true;
            insert(h1, i, nums[i]);
            update(h2, i, nums[i]);
        }
    }
    for (int i = 0; i < numsSize; i++) {
        if (!h2->data[i]) continue;
        printf("h2->data[%d]->val = %d, h2->data[%d]->max = %d\n", i, h2->data[i]->val, i, h2->data[i]->ind);
    }
    for (int i = 0; i < numsSize; i++) {
        if (!h2->data[i]) continue;
        if (h2->data[i]->ind == k) return true;
    }
    return false;
}

int main() {
    int n, k;
    scanf("%d%d", &n, &k);
    int num[n];
    for (int i = 0; i < n; i++) scanf("%d", &num[i]);
    printf("result = %d\n", containsNearbyDuplicate(num, n, k));
    return 0;
}
