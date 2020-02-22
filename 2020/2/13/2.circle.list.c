/*************************************************************************
	> File Name: 2.circle.list.c
	> Author:赵睿 
	> Mail: 1767153298@qq.com
	> Created Time: 2020年02月13日 星期四 15时59分11秒
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>
#include<time.h>

typedef struct node {
    int data;
    struct node *next;
} Node;

typedef struct list {
    Node *head;
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
    list->head = NULL;
    list->length = 0;
    return list;
}

void insert(List *list, int ind, int val) {
    if (!list) return ;
    if (ind < 0 || ind > list->length) return ;
    Node *p = list->head, *node = new_node(val);
}

int main() {

    return 0;
}
