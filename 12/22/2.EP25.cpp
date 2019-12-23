/*************************************************************************
	> File Name: 2.EP25.cpp
	> Author:赵睿 
	> Mail: 1767153298@qq.com
	> Created Time: 2019年12月22日 星期日 14时07分58秒
 ************************************************************************/

#include<iostream>
#include<cstdio>
#include<math.h>
#define max_n 1000
using namespace std;

int f[3][max_n + 5];

int main() {
    int n = 2;
    f[1][0] = 1, f[1][1] = 1;
    f[2][0] = 1, f[2][1] = 1;
    while (f[n % 3][0] < 1000) {
        n += 1;
        int *a = f[n % 3], *b = f[(n - 1) % 3], *c = f[(n - 2) % 3];
        for (int i = 1; i <= b[0]; i++) {
            a[i] = b[i] + c[i];
        }
        a[0] = b[0];
        for (int i = 1; i <= a[0]; i++) {
            if (a[i] < 10) continue;
            a[i + 1] += a[i] / 10;
            a[i] %= 10;
            a[0] += (i == a[0]);
        }
    }
    printf("%d\n", n);
    //for (int i = f[n % 3][0]; i >= 1; i--) {
    //    printf("%d", f[n % 3][i]);
    //}
    //printf("\n");
    return 0;
}
