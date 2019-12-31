/*************************************************************************
	> File Name: prime_sieve.cpp
	> Author: 
	> Mail: 
	> Created Time: 2019年12月11日 星期三 20时21分50秒
 ************************************************************************/

#include<iostream>
#include<cstdio>
#include<string>
#include<cstring>
#include<math.h>
#include<inttypes.h>
#include<stdarg.h>
#include<stdlib.h>
using namespace std;


void prime_sieve(int *a, int n) {
    a[0] = 0, a[1] = 0;
    for (int i = 2; i <= n; i++) {
        if (a[i] == 1) {
            int k = i;
            while (k * i <= n) {
                a[k * i] = 0;
                k++;
            }
        }
    }
}


int main () {
    int a[1005] = {1}, n = 500;
    /*for (int i = 2; i * i <= 1000; i++) {
        if (!a[i]) {
            for (int j = 2 * j; j <=1000; j += i) {
                a[i] = 1;
            }
        }
    }
    printf("%d\n", a[30]);*/
    prime_sieve(a, n);
    for (int i = 0; i <= 20; i++) {
       if (a[i] == 1) printf("%d ", i);
    }
    return 0;
}
