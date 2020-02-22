/*************************************************************************
	> File Name: 8.linkedlist.c
	> Author:赵睿 
	> Mail: 1767153298@qq.com
	> Created Time: 2020年01月27日 星期一 22时56分10秒
 ************************************************************************/

#include <stdio.h>
#include <stdlib.h>

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
    while (temp->next && count < index - 1) {
        temp = temp->next;
        count++;
    }
    if (count == index - 1) {
        node->next = temp->next;
        temp->next = node;
        printf("success\n");
        return head;
    }
    printf("failed\n");
    free(node);
    return head;
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
	if (!head) return;
    Node *node = head;
    while (head) {
        head = head->next;
        free(node);
        node = head;
    }
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
    clear(linkedlist);
    return 0;
}
