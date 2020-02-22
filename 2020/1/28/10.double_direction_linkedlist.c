/*************************************************************************
	> File Name: 10.double_direction_linkedlist.c
	> Author:赵睿 
	> Mail: 1767153298@qq.com
	> Created Time: 2020年01月28日 星期二 23时05分03秒
 ************************************************************************/

#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<sys/wait.h>

typedef struct Node {
    int data;
    struct Node *prior, *next;
} Node;

typedef struct List {
    Node *head;
} List;

void insert(List *list, int data) {
    Node *new_node = (Node *) malloc(sizeof(Node));
    new_node->data = data;
    new_node->next = NULL;
    if (!list->head) {
        list->head = new_node;
        return ;
    }
    Node *current_node = list->head;
    while (current_node->next) current_node = current_node->next;
    current_node->next = new_node;
    return ;
}

void change(List *list) {
    Node *current_node = list->head;
    while (current_node->next) current_node = current_node->next;
    current_node->next = list->head;
    list->head->prior = current_node;

    current_node = list->head->next;
    Node *pre_node = list->head;
    while (current_node != list->head) {
        current_node->prior = pre_node;
        pre_node = current_node;
        current_node = current_node->next;
    }
}

Node *search(List *list, int data) {
    Node *current_node = list->head;
    while (current_node) {
        if (current_node->data == data) return current_node;
        current_node = current_node->next; 
    }
}

void output(Node *head) {
    printf("%d", head->data);
    Node *current_node =  head->prior;
    while (current_node != head) {
        printf(" %d", current_node->data);
        current_node = current_node->prior;
    }
    printf("\n");
}

int main() {
    List *list = (List *) malloc(sizeof(List));
    list->head = NULL;
    int n;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        int a;
        scanf("%d", &a);
        insert(list, a);
    }
    change(list);
    int m;
    scanf("%d", &m);
    Node *head = search(list, m);
    output(head);
    return 0;
}
