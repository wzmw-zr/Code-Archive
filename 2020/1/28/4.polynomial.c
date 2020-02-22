/*************************************************************************
	> File Name: 4.polynomial.c
	> Author:赵睿 
	> Mail: 1767153298@qq.com
	> Created Time: 2020年01月28日 星期二 16时47分53秒
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/wait.h>
#include<math.h>

typedef struct Node {
    int c, e;
    struct Node *next;
} Node;

typedef struct LinkedList {
    Node *head;
} LinkedList;

void insert(LinkedList *linkedlist, int c, int e) {
    Node *new_node = (Node *) malloc(sizeof(Node));
    new_node->c = c;
    new_node->e = e;
    new_node->next = NULL;
    if (!linkedlist->head) {
        linkedlist->head = new_node;
        return ;
    }
    Node *current_node = linkedlist->head;
    while (current_node->next) current_node = current_node->next;
    current_node->next = new_node;
}

void calculate(LinkedList *linkedlist, int x) {
    int res = 0;
    Node *current_node = linkedlist->head;
    while (current_node) {
        res += current_node->c * pow(x, current_node->e);
        current_node = current_node->next;
    }
    printf("%d\n", res);
}

void output(LinkedList *linkedlist) {
    Node *current_node = linkedlist->head;
    while (current_node) {
        printf("c = %d, e = %d\n", current_node->c, current_node->e);
        current_node = current_node->next;
    }
}

int main() {
    LinkedList *linkedlist = (LinkedList *) malloc(sizeof(LinkedList));
    linkedlist->head = NULL;
    int m;
    scanf("%d", &m);
    for (int i = 1; i <= m; i++) {
        int c, e;
        scanf("%d%d", &c, &e);
        insert(linkedlist, c, e);
    }
    int x;
    scanf("%d", &x);
    calculate(linkedlist, x);
    return 0;
}
