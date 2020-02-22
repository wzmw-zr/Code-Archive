/*************************************************************************
	> File Name: 1.sequence.list.cpp
	> Author:赵睿 
	> Mail: 1767153298@qq.com
	> Created Time: 2020年02月11日 星期二 14时52分08秒
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>
#include<time.h>

typedef struct vector {
    int *data;
    int size, length;
} Vector;

Vector *init(int n) {
    Vector *vec = (Vector *) calloc(1, sizeof(Vector));
    vec->data = (int *) calloc(n, sizeof(int));
    vec->size = n;
    vec->length = 0;
    return vec;
}

int expand(Vector *vec) {
    int extr_size = vec->size;
    int *p;
    while (extr_size) {
        p = (int *) realloc(vec->data, sizeof(int) * (vec->size + extr_size));
        if (p) break;
        extr_size /= 2;
    }
    if (!p) return 0;
    printf("p = %p\n", p);
    vec->data = p;
    vec->size += extr_size;
    return 1;
}

int insert(Vector *vec, int ind, int val) {
    if (!vec) return 0;
    if (ind > vec->length || ind < 0) return 0;
    if (vec->length == vec->size) {
        if (!expand(vec)) {
            printf("expand failed!\n");
            return 0;
        }
        printf("expand successfully! size = %d\n", vec->size);
    }
    for (int i = vec->length; i > ind; i--) vec->data[i] = vec->data[i - 1];
    vec->data[ind] = val;
    vec->length += 1;
    return 1;
}

int erase(Vector *vec, int ind) {
    if (!vec) return 0;
    if (ind < 0 || ind >= vec->length) return 0;
    for (int i = ind + 1; i < vec->length; i++) vec->data[i - 1] = vec->data[i];
    vec->length -= 1;
    return 1;
}

void output(Vector *vec) {
    if (!vec) return ;
    printf("Vector(%d) = [", vec->length);
    for (int i = 0; i < vec->length; i++) {
        i && printf(", ");
        printf("%d", vec->data[i]);
    }
    printf("]\n\n");
}

void clear(Vector *vec) {
    if (!vec) return ;
    free(vec->data);
    free(vec);
    return ;
}

int main() {
    srand(time(0));
    #define max_op 20 
    Vector *vec = init(2);
    int op, ind, val;
    for (int i = 0; i < max_op; i++) {
        op = rand() % 4;
        ind  = rand() % (vec->length + 3) - 1;
        val = rand() % 100;
        switch (op) {
            case 0:
            case 1:
            case 2:{
                printf("insert %d at %d to vector = %d\n", val, ind, insert(vec, ind, val));
                break;
            }

            case 3: {
                printf("erase item at %d from vector = %d\n", ind, erase(vec, ind));
                break;
            }
        }
        output(vec);
        printf("%n");
    }
    output(vec);
    printf("%n");
    clear(vec);
    return 0;
}
