/*************************************************************************
	> File Name: 17.random.cpp
	> Author:赵睿 
	> Mail: 1767153298@qq.com
	> Created Time: 2019年12月23日 星期一 17时15分10秒
 ************************************************************************/

#include<iostream>
#include<cstdio>
#include<string>
#include<cstring>
#include<math.h>
#include<inttypes.h>
#include<stdarg.h>
#define max_n 100
#define max_r 1000
using namespace std;

int num[max_r + 5] = {0};
int randoms[max_n + 5] = {0};

int main() {
    int n, count = 0;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        scanf("%d", &randoms[i]);
    }
    for (int i = 1; i <= n; i++) {
        num[randoms[i]]++;
    }
    for (int i = 1; i <= max_r; i++) {
        if (num[i] == 0) continue;
        count++;
    }
    printf("%d\n", count);
    for (int i = 1; i <= max_r; i++) {
        if (num[i] == 0) continue;
        count--;
        count && printf("%d ", i);
        !count && printf("%d", i);
    }
    return 0;
}
