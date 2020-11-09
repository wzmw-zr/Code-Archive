/*************************************************************************
	> File Name: 2.large.number.mul.cpp
	> Author:赵睿 
	> Mail: 1767153298@qq.com
	> Created Time: 2019年12月22日 星期日 22时39分22秒
 ************************************************************************/

#include<iostream>
#include<cstdio>
#include<string>
#include<cstring>
#include<math.h>
#include<inttypes.h>
#include<stdarg.h>
#define max_n 1000
using namespace std;

int a[max_n + 5] = {0};

void mul(int m, int n) {
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= a[0]; j++) {
            a[j] *= m;
        }
        for (int k = 1; k <= a[0]; k++) {
            if (a[k] < 10) continue;
            a[k + 1] += a[k] /10;
            a[k] %= 10;
            a[0] += (k == a[0]);
        }
    }
    for (int i = a[0]; i >= 1; i--) {
        printf("%d", a[i]);
    }
    printf("\n");
}

int main() {
    a[0] = 1, a[1] = 1;
    int m, n; 
    scanf("%d%d", &m, &n);
    mul(m, n);
    return 0;
}
