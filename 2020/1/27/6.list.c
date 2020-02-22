/*************************************************************************
	> File Name: 6.list.c
	> Author:赵睿 
	> Mail: 1767153298@qq.com
	> Created Time: 2020年01月27日 星期一 19时59分55秒
 ************************************************************************/

#include<stdio.h>
#include <stdlib.h>
#include<unistd.h>
#include<sys/wait.h>
#include<string.h>

#define ERROR 0
#define OK 1

typedef struct Vector {
    int size, length;
    int *data;
} Vector;

void init(Vector *vector, int size) {
    vector->size = size, vector->length = 0;
    vector->data = (int *) malloc(sizeof(int) * size);
}

void expand(Vector *vector) {
    int *old_data = vector->data;
    vector->size *= 2;
    vector->data = (int *) malloc(sizeof(int) * vector->size);
    for (int i = 0; i < vector->length; i++) {
        vector->data[i] = old_data[i];
    }
}

int insert(Vector *vector, int loc, int value) {
    if (loc < 0 || loc > vector->length) return ERROR;
    if (vector->size == vector->length) expand(vector);
    for (int i = vector->length; i > loc; i--) vector->data[i] = vector->data[i - 1];
    vector->data[loc] = value;
    vector->length++;
    return OK;
}

int search(Vector *vector, int value) {
    for (int i = 0; i < vector->length; i++) {
        if (vector->data[i] == value) return OK;
    }
    return ERROR;
}

int delete_node(Vector *vector, int index) {
    if (index < 0 || index >= vector->length) return ERROR;
    for (int i = index; i < vector->length - 1; i++) {
        vector->data[i] = vector->data[i + 1];
    }
    vector->length--;
    return OK;
}

void print(Vector *vector) {
    for (int i = 0; i < vector->length; i++) {
        i && printf(" ");
        printf("%d", vector->data[i]);
    }
    printf("\n");
}

void clear(Vector *vector) {
    free(vector->data);
    free(vector);
}

int main() {
    Vector *vector = (Vector *)malloc(sizeof(Vector));
    init(vector, 20);
    int m, t;
    scanf("%d", &m);
    for (int i = 1; i <= m; i++) {
        scanf("%d", &t);
        switch (t) {
            case 1: {
                int a, b;
                scanf("%d%d", &a, &b);
                if (insert(vector, a, b)) printf("success\n");
                else printf("failed\n");
                break;
            }

            case 2: {
                int a;
                scanf("%d", &a);
                if (delete_node(vector, a)) printf("success\n");
                else printf("failed\n");
                break;
            }
            case 3: {
                int a;
                scanf("%d", &a);
                if (search(vector, a)) printf("success\n");
                else printf("failed\n");
                break;
            }
            case 4: {
                print(vector);
                break;
            }
        }
    }
    return 0;
}

