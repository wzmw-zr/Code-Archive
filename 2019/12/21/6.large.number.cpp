/*************************************************************************
	> File Name: 6.large.number.cpp
	> Author:赵睿 
	> Mail: 1767153298@qq.com
	> Created Time: 2019年12月21日 星期六 18时03分09秒
 ************************************************************************/

#include<iostream>
#include<cstdio>
#include<string>
#include<cstring>
using namespace std;

void get_val(int x, int *fac) {
    fac[0] = 1, fac[1] = 1;
    while (x >= 1) {
        for (int j = 1; j <= fac[0]; j++) {
            //printf("j = %d\n", j);
            fac[j] *= x;
        }
        for (int j = 1; j <= fac[0]; j++) {
            if (fac[j] < 10) continue;
            while (fac[j] >= 10) {
                fac[j + 1] += fac[j] / 10;
                fac[j] %= 10;
            }
            fac[0] += (j == fac[0]);
        }
        x--;
    }
}


void get_res(int *fac, int *res) {
    res[0] = 1, res[1] = 1;
    for (int i = 1; i <= fac[0]; i++) {
        if (fac[i]) {
            for (int j = 1; j <= res[0]; j++) {
                res[j] *= fac[i];
            }
            for (int j = 1; j <= res[0]; j++) {
                if (res[j] < 10) continue;
                res[j + 1] += res[j] / 10;
                res[j] %= 10;
                res[0] += (j == res[0]);
            }
        }
    }
}

int main() {
    int x;
    int fac[1500] = {0};
    int res[1500] = {0};
    while (~scanf("%d", &x)) {
        memset(fac, 0, sizeof(fac));
        memset(res, 0, sizeof(res));
        get_val(x, fac);
        get_res(fac, res);
        for (int i = res[0]; i >= 1; i--) {
            printf("%d", res[i]);
        }
        printf("\n");
    }
    return 0;
}
