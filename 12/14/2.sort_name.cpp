/*************************************************************************
	> File Name: 2.sort_name.cpp
	> Author:赵睿 
	> Mail: 1767153298@qq.com
	> Created Time: 2019年12月14日 星期六 09时19分49秒
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
    char name[10][25];
    int i = 10;
    while (i) {
        scanf("%s", &name[i]);
        i--;
    }
    for (i = 0; i < 10; i++) {
        for (int j = 0; j < 10 - i; j++) {
            if (strcmp(name[j - 1], name[j]) > 0) {
                char temp[25];
                strcpy(temp, name[j - 1]);
                strcpy(name[j - 1], name[j]);
                strcpy(name[j], temp);
            }
        }
    }
    
    for (int i = 0; i < 10; i++) {
        printf("%s\n", name[i]);
    }
    return 0;
}

