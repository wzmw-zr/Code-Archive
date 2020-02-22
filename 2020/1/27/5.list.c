/*************************************************************************
	> File Name: 5.list.c
	> Author:赵睿 
	> Mail: 1767153298@qq.com
	> Created Time: 2020年01月27日 星期一 18时05分27秒
 ************************************************************************/

#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<sys/wait.h>
#include<string.h>
#define ERROR 0
#define OK 1
typedef struct Vector {
    int size, length;
    int *data;
} vector;

void init(vector *a, int size) {
    a->size = size;
    a->length = 0;
    a->data = (int *) malloc(sizeof(int) * size);
}

void expand(vector *a) {
    printf("expand\n");
    int *old_data = a->data;
    a->size *= 2;
    a->data = (int *) malloc(sizeof(int) * a->size);
    for (int i = 0; i < a->length; i++) {
        a->data[i] = old_data[i];
    }
    free(old_data);
}

int insert(vector *a, int loc, int value) {
    if (loc < 0 || loc > a->length) {
        printf("failed\n");
        return ERROR;
    }
    if (a->size == a->length) {
        expand(a);
    }
    for (int i = a->length; i > loc; i--) {
        a->data[i] = a->data[i - 1];
    }
    a->data[loc] = value;
    printf("success\n");
    a->length += 1;
    return OK;
}

void clear(vector *a) {
    free(a->data);
    free(a);
}

int main() {
    vector *a = (vector *) malloc(sizeof(vector));
    int n;
    scanf("%d", &n);
    init(a, 5);
    int p, q;
    for (int i = 1; i <= n; i++) {
        scanf("%d%d", &p, &q);
        insert(a, p, q);
    }
    return 0;
}
