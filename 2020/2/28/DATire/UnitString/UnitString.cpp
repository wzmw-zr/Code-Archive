/*************************************************************************
	> File Name: UnitString.cpp
	> Author:赵睿 
	> Mail: 1767153298@qq.com
	> Created Time: 2020年02月28日 星期五 14时54分12秒
 ************************************************************************/

#include<cstdlib>
#include<cstring>
#include "UnitString.h"
using namespace std;

UnitString *NewUnitString(char *str) {
    UnitString *p = (UnitString *) calloc(sizeof(UnitString), 1);
    p->str = strdup(str);
    p->len = strlen(str);
    p->handled_cnt = 0;
    p->cur_ind = 1;
    return p;
}

void clearUnitString(UnitString *p) {
    if (!p) return ;
    free(p->str);
    free(p);
}
