/*************************************************************************
	> File Name: 1.sort_name.cpp
	> Author:赵睿 
	> Mail: 1767153298@qq.com
	> Created Time: 2019年12月15日 星期日 01时04分16秒
 ************************************************************************/

#include<iostream>
#include<cstdio>
#include<string>
#include<cstring>
#include<math.h>
#include<inttypes.h>
#include<stdarg.h>
using namespace std;


void swap_str(char *a, char *b) {
    char c[25];
    strcpy(c, a);
    strcpy(a, b);
    strcpy(b, c);
    return ;
}


int main () {
    char a[10][25];
    for (int i = 0; i < 10; i++) {
        scanf("%s", a + i);
    }
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 9 - i; j++) {
            if (strcmp(a[j], a[j + 1]) > 0) swap_str(a[j], a[j + 1]);
        }
    }

    for (int i = 0; i < 10; i++) printf("%s\n", a[i]);
    /*for (int i = 0; i < 10; i++) {
        printf("%s\n", a + i);
    }
    */

   /* scanf("%s%s", a, b);
    if (strcmp(a, b) < 0) {
        char c[25];
        strcpy(c, a);
        strcpy(a, b);
        strcpy(b, c);
    }
    printf("%s\n%s\n", a, b);
   */
    return 0;
}
