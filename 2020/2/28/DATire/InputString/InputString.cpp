/*************************************************************************
	> File Name: InputString.cpp
	> Author:赵睿 
	> Mail: 1767153298@qq.com
	> Created Time: 2020年02月28日 星期五 14时58分10秒
 ************************************************************************/

#include "InputString.h"

InputString *NewInputString(int size) {
    InputString *p = (InputString *) calloc(sizeof(InputString), 1);
    p->data = (UnitString **) calloc(sizeof(UnitString *), size);
    p->size = size;
    p->handled_number = 0;
    return p;
}

void clearInputString(InputString *p) {
    if (!p) return ;
    for (int i = 0; i < p->size; i++) clearUnitString(p->data[i]);
    free(p->data);
    free(p);
}

