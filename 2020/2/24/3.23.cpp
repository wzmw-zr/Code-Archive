/*************************************************************************
	> File Name: 3.23.cpp
	> Author:赵睿 
	> Mail: 1767153298@qq.com
	> Created Time: 2020年02月24日 星期一 20时20分49秒
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct ListNode {
    int val;
    struct ListNode *next;
};
typedef struct ListNode ListNode; 

typedef struct Heap {
    ListNode **data;
    int size, cnt;
} Heap;

Heap *init() {
    Heap *h = (Heap *) malloc(sizeof(Heap));
    h->data = (ListNode **) malloc(sizeof(ListNode *) * 1001);
    h->size = 1000;
    h->cnt = 0;
    return h;
}

ListNode *NewListNode(int val) {
    ListNode *l = (ListNode *) malloc(sizeof(ListNode));
    l->val = val;
    l->next = NULL;
    return l;
}

void expand(Heap *h) {
    int expand_size = h->size;
    ListNode **p;
    while (expand_size) {
        p = (ListNode **) realloc(h->data, sizeof(ListNode *) * (h->size + expand_size + 5));
        if (p) break;
        expand_size >>= 1;
    }
    if (!p) return ;
    h->data = p;
    h->size += expand_size;
}

void swap(ListNode **a, ListNode **b) {
    ListNode *temp = *a;
    *a = *b;
    *b = temp;
}

void push_heap(Heap *h, ListNode *p) {
    if (h->size == h->cnt) expand(h);
    h->data[++h->cnt] = p;
    int ind = h->cnt;
    while (ind >> 1 && h->data[ind]->val > h->data[ind >> 1]->val) {
        swap(&h->data[ind], &h->data[ind >> 1]);
        ind >>= 1;
    }
}

ListNode *pop(Heap *h) {
    ListNode *ret = h->data[1];
    ret->next = NULL;
    swap(&h->data[1], &h->data[h->cnt--]);
    int ind = 1;
    while ((ind << 1) <= h->cnt) {
        int temp = ind, l = ind << 1, r = ind << 1 | 1;
        if (l <= h->cnt && h->data[temp]->val < h->data[l]->val) temp = l;
        if (r <= h->cnt && h->data[temp]->val < h->data[r]->val) temp = r;
        if (temp == ind) break;
        swap(&h->data[ind], &h->data[temp]);
        ind = temp;
    }
    return ret;
}

void clear(Heap *h) {
    if (!h) return ;
    free(h->data);
    free(h);
}

ListNode *insert(ListNode *head, ListNode *p) {
    p->next = head;
    head = p;
    return head;
}

struct ListNode* mergeKLists(struct ListNode** lists, int listsSize){
    Heap *h = init();
    for (int i = 0; i < listsSize; i++) {
        ListNode *head = lists[i];
        while (head) {
            push_heap(h, head);
            head = head->next;
        }
    }
    ListNode *ret, *temp;
    while (h->cnt) {
        temp = pop(h); 
        ret = insert(ret, temp);    
    }
    return ret;
}

void output(ListNode *head) {
    printf("[");
    while (head) {
        printf("%d ", head->val);
        head = head->next;
    }
    printf("]\n");
}

int main() {
    ListNode *lists[3] = {0};
    int n1, n2, n3;
    scanf("%d%d%d", &n1, &n2, &n3);
    //printf("%d %d %d\n", n1, n2, n3);
    int m;
    for (int i = 0; i < n1; i++) {
        scanf("%d", &m);
        lists[0] = insert(lists[0], NewListNode(m));
    }
    output(lists[0]);
    for (int i = 0; i < n2; i++) {
        scanf("%d", &m);
        lists[1] = insert(lists[1], NewListNode(m));
    }
    output(lists[1]);
    for (int i = 0; i < n3; i++) {
        scanf("%d", &m);
        lists[2] = insert(lists[2], NewListNode(m));
    }
    output(lists[2]);
    ListNode *res = mergeKLists(lists, 3);
    for (int i = 1; i <= 8; i++) {
        printf("%d ", res->next != NULL ? 1 : 0);
        res = res->next;
    }
    printf("\n");
    return 0;
}
