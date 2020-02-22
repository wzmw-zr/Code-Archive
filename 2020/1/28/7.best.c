/*************************************************************************
	> File Name: 7.best.c
	> Author:赵睿 
	> Mail: 1767153298@qq.com
	> Created Time: 2020年01月28日 星期二 19时43分52秒
 ************************************************************************/

#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<sys/wait.h>

typedef struct Paper {
    int id;
    struct Paper *next;
} Paper;

typedef struct List {
    Paper *head;
} List;

void insert(List *list, int id) {
    Paper *new_paper = (Paper *) malloc(sizeof(Paper));
    new_paper->id = id;
    new_paper->next = NULL;
    if (!list->head) {
        list->head = new_paper;
        return ;
    }
    Paper *current_paper = list->head;
    while (current_paper->next) current_paper = current_paper->next;
    current_paper->next = new_paper;
    return ;
}

void delete(List *list, int num) {
    Paper *current_paper = list->head;
    if (num == 1) {
        list->head = current_paper->next;
        free(current_paper);
        return ;
    }
    int count = 1;
    while (count < num - 1) current_paper = current_paper->next, count++;
    Paper *delete_paper = current_paper->next;
    current_paper->next = delete_paper->next;
    free(delete_paper);
    return ;
}

void get_best(List *list, int num) {
    int mid = num >> 1, count = 0;
    Paper *current_paper = list->head;
    while (count < mid) current_paper = current_paper->next, count++;
    printf("%d\n", current_paper->id);
}

void output(List *list) {
    Paper *current_paper = list->head;
    int count = 0;
    while (current_paper) {
        count && printf(" ");
        printf("%d", current_paper->id);
        current_paper = current_paper->next;
        count++;
    }
    printf("\n");
}

int main() {
    List *list = (List *) malloc(sizeof(List));
    list->head = NULL;
    int n, m;
    scanf("%d%d", &n, &m);
    int number = n - m;
    for (int i = 1; i <= n; i++) insert(list, i);
    int num;
    for (int i = 1; i <= m; i++) {
        scanf("%d", &num);
        delete(list, num);
    }
    get_best(list, number);
    return 0;
}
