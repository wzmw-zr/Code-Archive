/*************************************************************************
	> File Name: EP30.cpp
	> Author:赵睿 
	> Mail: 1767153298@qq.com
	> Created Time: 2019年12月17日 星期二 08时35分37秒
 ************************************************************************/

#include<iostream>
#include<cstdio>
#include<string>
#include<cstring>
#include<math.h>
#include<inttypes.h>
#include<stdarg.h>
#define MAX_N 1000000
using namespace std;


int is_val(int n) {
    int x = n, y = 0;
    while (x) {
        y += pow((x % 10), 5);
        x /= 10;
    }
    if (n == (int) y) return 1;
    else return 0;
}


int main() {
    int sum = 0;
    for (int i = 2; i < MAX_N; i++) {
        if (is_val(i)) sum += i;
    }
    printf("%d", sum);
    return 0;
}
