/*************************************************************************
	> File Name: 8.cpp
	> Author: 
	> Mail: 
	> Created Time: 2019年12月03日 星期二 20时04分28秒
 ************************************************************************/

#include<iostream>
#include<cstdio>
#include<string>
#include<cstring>
#include<math.h>
#include<stdlib.h>
#include<time.h>
using namespace std;

int main() {
    int a, b;
    srand(time(0));
    scanf("%d%d", &a, &b);
    if (a - b) printf("not equal\n");//a - b 当其值不为0时，执行，否则执行else中语句
    else printf("equal\n");

    if ((a++) && (b++)) printf("true\n");
    else printf("false\n");
    if ((a++) || (b++)) printf("true\n");
    else printf("false\n");
    printf("a = %d, b = %d", a, b);
//当要求最后一个输出结果没有空格或者其他时的常用操作
    for (int i = 0; i < 10; i++) {
        i && printf(" ");
        //if (i) printf(" ");
        printf("%d", i);
    }
    printf("\n");
    int count = 0;
    for (int i = 0; i < 10; i++) {
        int val = rand() % 100;
        count += !(val & 1); //偶数的个数
        //count += val % 2;
        //count += val & 1; 
        //if (val % 2) count++; 
        i && printf(" ");
        printf("%d", val);
    }
    printf("\n");
    printf("odd numbers : %d", count);
    return 0;
}
