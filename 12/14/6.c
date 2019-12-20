/*************************************************************************
	> File Name: 6.c
	> Author:赵睿 
	> Mail: 1767153298@qq.com
	> Created Time: 2019年12月14日 星期六 20时25分50秒
 ************************************************************************/

#include<stdio.h>

struct Data {
    int x, y;
};


int main () {
    struct Data a[2];
    struct Data *p = a;
    a[0].x = 1;
    a[0].y = 2;
    a[1].x = 3;
    a[1].y = 4;
    printf("%d\n", (a + 1)->x);
    printf("%d\n", (*p).x);
    //printf("%d\n", *(p + 1)->x);
    return 0;
}

