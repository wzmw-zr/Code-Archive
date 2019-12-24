/*************************************************************************
	> File Name: 3.EP43.cpp
	> Author:赵睿 
	> Mail: 1767153298@qq.com
	> Created Time: 2019年12月24日 星期二 10时40分35秒
 ************************************************************************/

#include<iostream>
#include<cstdio>
#include<string>
#include<cstring>
#include<math.h>
#include<inttypes.h>
#include<stdarg.h>
using namespace std;

int num[10] = {0};
int exist[10] = {0};
long sum = 0;


//int is_val(long x) {
    //int num[10] = {2, 3, 5, 7, 11, 13, 17};
    //for (int i = 0; i <= 6; i++) {
        //long p = pow(10, 6 - i), temp = (x / p) % 1000;
        //if (temp % num[i]) return 0;
    //}
    //return 1;
//}

int is_val(long n) {
    long number[7] = {2, 3, 5, 7, 11, 13, 17};
    long i = 6, temp;
    while (i >= 0) {
        long p = pow(10, i);
        temp = (n / p) % 1000;
        if (temp % number[6 - i]) return 0;
        i--;
    }
    return 1;
}

void get_val() {
    long ans = 0;
    for (int i = 0; i <= 9; i++) ans = ans * 10 + num[i];
    printf("ans = %lld\n", ans);
    if (is_val(ans)) sum += ans;
}

void solve(int n) {
    if (n == 0) get_val();
    if (n == 10) {
        for (int i = 1; i <= 9; i++) {
            memset(num, 0, sizeof(num));
            memset(exist, 0, sizeof(exist));
            num[0] = i;
            exist[i] = 1;
            solve(n - 1);
        }
    } else {
        for (int i = 0; i <= 9; i++) {
            if (exist[i]) continue;
            num[10 - n] = i;
            exist[i] = 1;
            solve(n - 1);
        }
    }
}

int main() {
    solve(10);
    printf("%lld\n", sum);
    return 0;
}
