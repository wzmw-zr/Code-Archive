/*************************************************************************
	> File Name: UnitString.h
	> Author:赵睿 
	> Mail: 1767153298@qq.com
	> Created Time: 2020年02月28日 星期五 14时52分09秒
 ************************************************************************/

#ifndef _UNITSTRING_H
#define _UNITSTRING_H

typedef struct UnitString {
    char *str;
    int len, handled_cnt, cur_ind;
} UnitString;

UnitString *NewUnitString(char *str);

void clearUnitString(UnitString *p);
#endif
