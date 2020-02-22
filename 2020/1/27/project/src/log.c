/** @file log.c */
#include <stdlib.h>
#include <string.h>
#include "log.h"

/**
对log进行初始化，log的“构造函数”
 */
void log_init(log_t *l) {
    l->head = NULL;
}

/**
销毁一个log，释放所有内存空间，log的“析构函数”
 */

void log_destroy(log_t* l) {
    node* head = l->head;
    node* temp = l->head;
    while (head->next) {
        head = head->next;
        free(temp);
        temp = head;
    }
    free(head);
    head = NULL;
}

/**
向log中推入一个字符串，你可以将log视为一个由链表组成的栈
 */

void log_push(log_t* l, const char *item) {
    node* head = l->head;
    char command[strlen(item) + 5];
    memset(command, 0, sizeof(command));
    strcpy(command, item);
    //printf("%s\n", command);
    if (head == NULL) {
        node* temp = (node*) malloc(sizeof(node));
        head = temp;
        l->head = head;
        (l->head)->next = NULL;
        (l->head)->cmd = command;
        // the first element of the link list
        //l->head = head;
        printf("%s\n", (l->head)->cmd);
    } else {
        while (head->next) head = head->next;
        node* tail = (node*) malloc(sizeof(node));
        tail->next = NULL;
        tail->cmd = command;
        head->next = tail;
    }
}


/**
搜索log中是否含有对应前缀的字符串
 */

char *log_search(log_t* l, const char *prefix) {
    node* head = l->head;
    int len = strlen(prefix), flag = 0;
    while (head) {
        for (int i = 0; i < len; i++) {
            if ((head->cmd)[i] == prefix[i]) continue;
            flag = 1;
            break;
        }
        if (!flag) break;
        flag = 0;
        head = head->next;
    }
    if (head) return head->cmd;
    return NULL;
}
