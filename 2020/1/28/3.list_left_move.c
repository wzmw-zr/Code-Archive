/*************************************************************************
	> File Name: 3.list_left_move.c
	> Author:赵睿 
	> Mail: 1767153298@qq.com
	> Created Time: 2020年01月28日 星期二 16时04分00秒
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/wait.h>

typedef struct List {
    int size;
    int *data;
} List;

void init(List *list, int size) {
    list->size = size;
    list->data = (int *) malloc(sizeof(int) * size);
}

void left_move(List *list) {
    int temp = list->data[0];
    for (int i = 1; i <= list->size - 1; i++) list->data[i - 1] = list->data[i];
    list->data[list->size - 1] = temp;
}

void output(List *list) {
    for (int i = 0; i < list->size; i++) {
        i && printf(" ");
        printf("%d", list->data[i]);
    }
    printf("\n");
}

int main() {
    List *list = (List *) malloc(sizeof(List));
    int n, k;
    scanf("%d%d", &n, &k);
    init(list, n);
    //printf("n = %d, k = %d\n", n, k);
    for (int i = 0; i < n; i++) scanf("%d", &(list->data[i]));
    for (int i = 1; i <= k; i++) left_move(list);
    output(list);
    return 0;
}
