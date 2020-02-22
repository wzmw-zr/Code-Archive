/*************************************************************************
	> File Name: 3.linked.list.cpp
	> Author:赵睿 
	> Mail: 1767153298@qq.com
	> Created Time: 2020年02月11日 星期二 19时08分11秒
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>
#include<time.h>

typedef struct listNode {
    int data;
    struct listNode *next;
} ListNode;

typedef struct List {
    ListNode head;
    int length;
} List;

ListNode *getNewNode(int val) {
    ListNode *p = (ListNode *) calloc(1, sizeof(ListNode));
    p->data = val;
    p->next = NULL;
    return p;
}

List *getLinkList() {
    List *p = (List *) calloc(1, sizeof(List));
    p->head.next = NULL;
    p->length = 0;
    return p;
}


int insert(List *l, int ind, int val) {
    if (!l) return 0;
    if (ind < 0 || ind > l->length) return 0;
    ListNode *p = &(l->head), *node = getNewNode(val);
    while (ind--) p = p->next;
    node->next = p->next;
    p->next = node;
    //remember what operation still need to complete
    l->length += 1;
    return 1; 
}

int erase(List *l, int ind) {
    if (!l) return 0;
    if (ind < 0 || ind >= l->length) return 0;
    ListNode *p = &(l->head), *node;
    while (ind--) p = p->next;
    node = p->next;
    p->next = node->next;
    free(node);
    l->length -= 1;
    return 1;
}

void output(List *l) {
    printf("List(%d) = [", l->length);
    for (ListNode *p = l->head.next; p; p = p->next) {
        printf("%d->", p->data);
    }
    printf("NULL]\n");
    return ;
}

void reverse(List *l) {
    if (!l) return ;
    ListNode *head = &(l->head), *p = head->next, *q;
    head->next = NULL;
    while (p) {
        q = p->next;
        p->next = head->next;
        head->next = p;
        p = q;
    }
}

void clear_ListNode(ListNode *node) {
    if (!node) return ;
    free(node);
    return ;
}

void clear_list(List *l) {
    if (!l) return ;
    ListNode *p = (l->head).next, *q;
    while (p) {
        q = p->next;
        clear_ListNode(p);
        p = q;
    }
    free(l);
    return ;
}


int main() {
    #define max_op 20
    srand(time(0));
    List *l = getLinkList();
    int op, ind, val;
    for (int i = 1; i <= max_op; i++) {
        op = rand() % 4;
        ind = rand() % (l->length + 3) - 1;
        val = rand() % 100;
        switch (op) {
            case 0:
            case 1: {
                printf("reverse ");
                reverse(l);
                break;
            }
            case 2: {
                printf("insert %d at %d to list = %d\n", val, ind, insert(l, ind, val));
                break;
            }

            case 3: {
                printf("erase item at %d from list = %d\n", ind, erase(l, ind));
                break;
            }
        }
        output(l);
        printf("\n");
    }    
    clear_list(l);
    return 0;
}
