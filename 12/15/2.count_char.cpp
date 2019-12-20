/*************************************************************************
	> File Name: 2.count_char.cpp
	> Author:赵睿 
	> Mail: 1767153298@qq.com
	> Created Time: 2019年12月15日 星期日 01时24分30秒
 ************************************************************************/

#include<iostream>
#include<cstdio>
#include<string>
#include<cstring>
#include<math.h>
#include<inttypes.h>
#include<stdarg.h>
using namespace std;




int main () {
    char c;
    int num[4] = {0};
    while (scanf("%c", &c) && c != '\n') {
        if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z')) num[0]++;
        else if  (c >= '0' && c <='9') num[1]++;
        else if (c == ' ') num[2]++;
        else num[3]++;
    }
    printf("%d %d %d %d", num[0], num[1], num[2], num[3]);
    return 0;
}
