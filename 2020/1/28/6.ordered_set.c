/*************************************************************************
	> File Name: 6.ordered_set.c
	> Author:赵睿 
	> Mail: 1767153298@qq.com
	> Created Time: 2020年01月28日 星期二 17时45分18秒
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/wait.h>

typedef struct Node {
    int data;
    struct Node *next;
} Node;

typedef struct LinkedList {
    Node *head;
} LinkedList;

void output(LinkedList *list);

void init(LinkedList *list) {
    list->head = NULL;
}

void insert(LinkedList *list, int data) {
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

void intersection(LinkedList *lista, LinkedList *listb, LinkedList *listc) {
    Node *current_a_node = lista->head;
    Node *current_b_node = listb->head;
    int count = 0;
    while (current_a_node && current_b_node) {
        if (current_a_node && current_b_node && current_a_node->data == current_b_node->data) { 
            insert(listc, current_a_node->data);
            current_a_node = current_a_node->next;
            current_b_node = current_b_node->next;
            count++;
        }
        while (current_a_node && current_b_node && current_a_node->data < current_b_node->data)
            current_a_node = current_a_node->next;
        while (current_b_node && current_b_node && current_b_node->data < current_a_node->data)  
            current_b_node = current_b_node->next;
    }
    printf("%d\n", count);
}

void output(LinkedList *list) {
    Node *current_node = list->head;
    int count = 0;
    while (current_node) {
        count && printf(" ");
        printf("%d", current_node->data); 
        current_node = current_node->next;
        count++;
    }
    printf("\n");
}

int main() { 
    LinkedList *lista = (LinkedList *) malloc(sizeof(LinkedList));
    init(lista);
    LinkedList *listb = (LinkedList *) malloc(sizeof(LinkedList));
    init(listb);
    LinkedList *listc = (LinkedList *) malloc(sizeof(LinkedList));
    init(listc);
    int n, a;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        scanf("%d", &a);
        insert(lista, a);
    }
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        scanf("%d", &a);
        insert(listb, a);
    }
    intersection(lista, listb, listc);
    output(listc);
    return 0;
}
