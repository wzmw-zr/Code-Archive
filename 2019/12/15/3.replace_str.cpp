/*************************************************************************
	> File Name: 3.replace_str.cpp
	> Author:赵睿 
	> Mail: 1767153298@qq.com
	> Created Time: 2019年12月15日 星期日 01时39分10秒
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
    char a[1000005];
    scanf("%[^\n]s", a);
    for (int i = 0; i < strlen(a); i++) {
        a[i] == ' ' && printf("%%20");
        a[i] != ' ' && printf("%c", a[i]);
    }
    return 0;
}
