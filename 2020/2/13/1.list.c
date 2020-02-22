/*************************************************************************
	> File Name: 1.list.c
	> Author:赵睿 
	> Mail: 1767153298@qq.com
	> Created Time: 2020年02月13日 星期四 14时34分35秒
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>
#include<time.h>

typedef struct node {
    int data;
    struct node *next;
} Node;

typedef struct list {
    Node head;
    int length;
} List;

Node *get_new_node(int val) {
    Node *node = (Node *) malloc(sizeof(Node));
    node->data = val;
    node->next = NULL;
    return node;
}

List *init_list() {
    List *list = (List *) malloc(sizeof(List));
    list->head.next = NULL;
    list->length = 0;
    return list;
}

void clear_node(Node *node) {
    if (!node) return ;
    free(node);
    return ;
}

void clear_list(List *list) {
    if (!list) return ;
    Node *node = list->head.next, *q;
    while (node) {
        q = node->next;
        clear_node(node);
        node = q;
    }
    return ;
}

int insert(List *list, int ind, int val) {
    if (!list) return -1;
    if (ind < 0 || ind > list->length) return -1;
    int ret = ind;
    Node *p = &(list->head), *node = get_new_node(val);
    while (ind--) p = p->next;
    node->next = p->next;
    p->next = node;
    list->length += 1;
    return ret;
}

int erase(List *list, int ind) {
    if (!list) return -1;
    if (ind < 0 || ind >= list->length) return -1;
    int ret = ind;
    Node *node = &(list->head), *q;
    while (ind--) node = node->next;
    q = node->next;
    node->next = q->next;
    free(q);
    list->length -= 1;
    return ret;
}

void output(List *l) {
    printf("head->");
    for (Node *p = l->head.next; p; p = p->next) {
        printf("%d->", p->data);
    }
    printf("NULL\n");
    return ;
}

/*int search(List *l, int val) {
    int ind = 0;
    Node *p = l->head.next;
    while (p && p->data != val) p = p->next, ind++;
    if (!p) return -1;
    return ind;
}
*/

void output_search(List *l, int ind) {
    char str[100];
    int offset = 3;
    Node *p = l->head.next;
    while (ind != -1 && p) {
        offset += sprintf(str, "%d->", p->data);
        ind--;
        p = p->next;
    }
    for (int i = 0; i < offset; i++) printf(" ");
    printf("^\n");
    for (int i = 0; i < offset; i++) printf(" ");
    printf("|\n\n");
    return ;
}

int main() {
    srand(time(0));
    #define max_op 20
    int op, ind, val, flag;
    List *l = init_list();
    for (int i = 1; i <= max_op; i++) {
        op = rand() % 4;
        ind = rand() % (l->length + 3) - 1;
        val = rand() % 100;
        switch (op) {
            case 0:
            case 1:
            case 2: {
                printf("insert %d at %d to list\n", val, ind);
                flag = insert(l, ind, val);
                break;
            }
            case 3: {
                printf("erase item at %d from list\n", ind);
                erase(l, ind);
                flag = -1;
                break;
            }
        }
        output(l);
        output_search(l, flag);
        printf("\n");
    }
    clear_list(l);
    return 0;
}
