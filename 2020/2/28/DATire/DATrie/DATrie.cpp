/*************************************************************************
	> File Name: DATrie.cpp
	> Author:赵睿 
	> Mail: 1767153298@qq.com
	> Created Time: 2020年02月28日 星期五 15时00分56秒
 ************************************************************************/

#include "DATrie.h"

DATrie *NewDATrie(int size) {
    DATrie *p = (DATrie *) calloc(sizeof(DATrie), 1);
    p->base = (int *) calloc(sizeof(int), size);
    p->check = (int *) calloc(sizeof(int), size);
    p->root = 1;
    p->size = size;
    p->check[p->root] = 1;
    return p;
}

void buildDATrie(DATrie *p, InputString *q) {

}

void clearDATrie(DATrie *p) {
    if (!p) return ;
    free(p->base);
    free(p->check);
    free(p);
}

