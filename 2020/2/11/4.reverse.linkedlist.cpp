/*************************************************************************
	> File Name: 4.reverse.linkedlist.cpp
	> Author:赵睿 
	> Mail: 1767153298@qq.com
	> Created Time: 2020年02月11日 星期二 20时17分47秒
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>

typedef struct node {
    int data;
    struct node *next;
} Node;

typedef struct list {
    Node head;
    int length;
} List;

Node *new_node(int val) {
    Node *node = (Node *) malloc(sizeof(Node));
    node->data = val;
    node->next = NULL;
    return node;
}

List *new_list() {
    List *list = (List *) malloc(sizeof(List));
    list->head.next = NULL;
    list->length = 0;
    return list;
}

int insert(List *l, int ind, int val) {
    if (!l) return 0;
    if (ind < 0 || ind > l->length) return 0;
    Node *p = &(l->head), *node = new_node(val);
    while (ind--) p = p->next;
    node->next = p->next;
    p->next = node;
    l->length += 1;
    return 1;
}


void reverse(List *l) {
    if (!l) return ;
    Node *head = &(l->head), *p = head->next, *q;
    head->next = NULL;
    while (p) {
        q = p->next;
        p->next = head->next;
        head->next = p;
        p = q;
    }
}


int main() {

    return 0;
}
