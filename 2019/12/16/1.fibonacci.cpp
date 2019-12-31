/*************************************************************************
	> File Name: 1.fibonacci.cpp
	> Author:赵睿 
	> Mail: 1767153298@qq.com
	> Created Time: 2019年12月16日 星期一 00时09分06秒
 ************************************************************************/

#include<iostream>
#include<cstdio>
#include<string>
#include<cstring>
#include<math.h>
#include<inttypes.h>
#include<stdarg.h>
using namespace std;


void fibonacci(int *a) {
    a[1] = 1, a[2] = 2;
    for (int i = 3; i < 100; i++) {
        a[i] = a[i - 1] + a[i - 2];
    }
}

int main() {
    int sum = 0, i = 1;
    int value[100];
    fibonacci(value);
    while (value[i] <= 4000000) {
        if (value[i] % 2 == 0) sum += value[i];
        i++; 
    }
    printf("%d\n", sum);
    return 0;
}
