/*************************************************************************
	> File Name: 19.max.number.cpp
	> Author:赵睿 
	> Mail: 1767153298@qq.com
	> Created Time: 2019年12月23日 星期一 18时28分24秒
 ************************************************************************/

#include<iostream>
#include<cstdio>
#include<string>
#include<cstring>
#include<math.h>
#include<inttypes.h>
#include<stdarg.h>
using namespace std;

int main() {
    int n, max = 0;
    scanf("%d", &n);
    int h[n + 5];
    for (int i = 1; i <= n; i++) {
        scanf("%d", &h[i]);
        if (max < h[i]) max = h[i];
    }
    printf("%d", max);
    return 0;
}
