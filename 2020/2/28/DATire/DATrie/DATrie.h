/*************************************************************************
	> File Name: DATrie.h
	> Author:赵睿 
	> Mail: 1767153298@qq.com
	> Created Time: 2020年02月28日 星期五 14时59分28秒
 ************************************************************************/

#ifndef _DATRIE_H
#define _DATRIE_H
#include "InputString.h"

typedef struct DATrie {
    int *base, *check;
    int root, size;
} DATrie;

DATrie *NewDATrie(int size);

void buildDATrie(DATrie *p, InputString *q);

void clearDATrie(DATrie *p);

#endif
