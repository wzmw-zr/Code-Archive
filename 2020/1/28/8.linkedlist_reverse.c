/*************************************************************************
	> File Name: 8.linkedlist_reverse.c
	> Author:赵睿 
	> Mail: 1767153298@qq.com
	> Created Time: 2020年01月28日 星期二 21时22分34秒
 ************************************************************************/

#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<sys/wait.h>

typedef struct Node {
    char c;
    struct Node *next;
} Node;

typedef struct List {
    Node *head;
} List;

void insert(List *list, char c) {
    Node *new_node = (Node *) malloc(sizeof(Node));
    new_node->c = c;
    new_node->next = NULL;
    if (!list->head) {
        list->head = new_node;
        return ;
    }
    Node *current_node = list->head;
    while (current_node->next) current_node = current_node->next;
    current_node->next = new_node;
}

void reverse(List *list) {
    Node *head = list->head;
    Node *current_node = head->next;
    head->next = NULL;
    while (current_node) {
        Node *next_node = current_node->next;
        current_node->next = head;
        head = current_node;
        current_node = next_node;
    }
    list->head = head;
}

void output(List *list) {
    Node *current_node = list->head;
    int count = 0;
    while (current_node) {
        count && printf(" ");
        printf("%c", current_node->c);
        current_node = current_node->next;
        count++;
    }
    printf("\n");
}

int main() {
    List *list = (List *) malloc(sizeof(List));
    list->head = NULL;
    int n;
    scanf("%d", &n);
    getchar();
    for (int i = 1; i <= n; i++) {
        char c;
        scanf("%c", &c);
        getchar();
        insert(list, c);
    }
    reverse(list);
    output(list);
    return 0;
}
