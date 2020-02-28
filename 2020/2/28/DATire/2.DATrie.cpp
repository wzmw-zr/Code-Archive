/*************************************************************************
	> File Name: 2.DATrie.cpp
	> Author:赵睿 
	> Mail: 1767153298@qq.com
	> Created Time: 2020年02月28日 星期五 14时32分36秒
 ************************************************************************/

#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<ctime>
using namespace std;

typedef struct UnitString {
    char *str;
    int len, handled_cnt, cur_ind;
} UnitString;

typedef struct InputString {
    UnitString **data;
    int size, handled_number;
} InputString;

typedef struct DATrie {
    int *base, *check;
    int root, size;
} DATrie;

UnitString *NewUnitString(char *str) {
    UnitString *p = (UnitString *) calloc(sizeof(UnitString), 1);
    p->str = strdup(str);
    p->len = strlen(str);
    p->handled_cnt = 0;
    p->cur_ind = 1;
    return p;
}

InputString *NewInputString(int size) {
    InputString *p = (InputString *) calloc(sizeof(InputString), 1);
    p->data = (UnitString **) calloc(sizeof(UnitString *), size);
    p->size = size;
    p->handled_number = 0;
    return p;
}

DATrie *NewDATrie(int size) {
    DATrie *p = (DATrie *) calloc(sizeof(DATrie), 1);
    p->base = (int *) calloc(sizeof(int), size);
    p->check = (int *) calloc(sizeof(int), size);
    p->root = 1;
    p->size = size;
    p->check[p->root] = 1;
    return p;
}

void clearUnitString(UnitString *p) {
    if (!p) return ;
    free(p->str);
    free(p);
}

void clearInputString(InputString *p) {
    if (!p) return ;
    for (int i = 0; i < p->size; i++) clearUnitString(p->data[i]);
    free(p->data);
    free(p);
}

void clearDATrie(DATrie *p) {
    if (!p) return ;
    free(p->base);
    free(p->check);
    free(p);
}

int main() {

    return 0;
}
