/*************************************************************************
	> File Name: 2.BigFrac.c
	> Author:赵睿 
	> Mail: 1767153298@qq.com
	> Created Time: 2020年07月14日 星期二 14时09分37秒
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int n;
int res[405];

int main() {
    scanf("%d", &n);
    res[0] = 1;
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j <= 400 && res[j]; j++) {
            res[j] *= i;
        }
        for (int j = 0; j <= 400 && res[j]; j++) {
            if (res[j] >= 10) {
                res[j + 1] += res[j] / 10;
                res[j] %= 10;
            }
        }
    }
    int ind = 400;
    while (res[ind] == 0) ind--;
    while (ind >= 0) printf("%d", res[ind--]);
    printf("\n");
    return 0;
}
