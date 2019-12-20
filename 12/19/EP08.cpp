/*************************************************************************
	> File Name: EP08.cpp
	> Author:赵睿 
	> Mail: 1767153298@qq.com
	> Created Time: 2019年12月19日 星期四 18时06分06秒
 ************************************************************************/

#include<iostream>
#include<cstdio>
#include<string>
#include<cstring>
#include<math.h>
#include<inttypes.h>
#include<stdarg.h>
#define MAX_N 1000
using namespace std;


char num[MAX_N + 5];

int main() {
    int len = 0;
    long long  ans = 0, count = 0, p = 1;
    while (~scanf("%s", num + len)) len += strlen(num + len);
    for (int i = 0; num[i]; i++) {
        num[i] -= '0';
        if (num[i]) p *= num[i];
        else count++;
        if (i < 13) continue;
        if (num[i - 13]) p /= num[i - 13];
        else count--;
        if (count == 0 && p > ans)  ans = p;
    }
    printf("%lld\n", ans);
    return 0;
}
