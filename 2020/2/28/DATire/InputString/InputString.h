/*************************************************************************
	> File Name: InputString.h
	> Author:赵睿 
	> Mail: 1767153298@qq.com
	> Created Time: 2020年02月28日 星期五 14时56分09秒
 ************************************************************************/

#ifndef _INPUTSTRING_H
#define _INPUTSTRING_H
#include "UnitString.h"

typedef struct InputString {
    UnitString **data;
    int size, handled_number;
} InputString;

InputString *NewInputString(int size);

void clearInputString(InputString *p);

#endif
