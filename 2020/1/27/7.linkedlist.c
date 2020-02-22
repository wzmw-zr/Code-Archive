/*************************************************************************
	> File Name: 7.linkedlist.c
	> Author:赵睿 
	> Mail: 1767153298@qq.com
	> Created Time: 2020年01月27日 星期一 21时47分34秒
 ************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include<unistd.h>
#include<sys/wait.h>
#include<string.h>

typedef struct Node{
    int data;
    struct Node *next;
}Node, *LinkedList;

LinkedList insert(LinkedList head, Node *node, int index) {
    if (!head) {
        if (index) {
            printf("failed\n");
            return head;
        }
        head = node;
        printf("success\n");
        return head;
    }
    if (!index) {
        node->next = head;
        head = node;
        printf("success\n");
        return head;
    }
    int count = 0;
    LinkedList temp = head;
    while (head->next && count < index - 1) {
        head = head->next;
        count++;
    }
    if (count == index - 1) {
        node->next = head->next;
        head->next = node;
        printf("success\n");
        return temp;
    }
    printf("failed\n");
    free(node);
    return temp;
}

void output(LinkedList head) {
    if (!head) return ;
    int count = 0;
    while (head) {
        count && printf(" ");
        printf("%d", head->data);
        head = head->next;
        count++;
    }
    printf("\n");
}

void clear(LinkedList head) {
    free(head);
}

int main() {
    LinkedList linkedlist = NULL;
    int n;
    scanf("%d", &n);
    int p, q;
    for (int i = 1; i <= n; i++) {
        scanf("%d%d", &p, &q);
        Node *node = (Node *) malloc(sizeof(Node));
        node->data = q;
        linkedlist = insert(linkedlist, node, p);
    }
    output(linkedlist);
    return 0;
}
