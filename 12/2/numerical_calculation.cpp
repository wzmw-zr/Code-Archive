/*************************************************************************
	> File Name: numerical_calculation.cpp
	> Author: 
	> Mail: 
	> Created Time: 2019年12月02日 星期一 00时51分12秒
 ************************************************************************/

#include<iostream>
#include<cstdio>
#include<string>
#include<cstring>
#include<math.h>
using namespace std;

int main () {
    int a, b, pre,  count = 0;
    scanf("%d%d", &a, &b);
    for (int i = a; i <= b; i++) {
        int flag = 0;
        int ab = i  / 100;
        int cd = i % 100;
        if (ab == ((int) sqrt(ab)) * ((int) sqrt(ab)) && cd == ((int) sqrt(cd)) * ((int) sqrt(cd))) {
            for (int j = 2; j <= sqrt(i); j++) {
                if (i % j == 0) {
                    flag = 1;
                    break;
              }
            }
            if (flag == 0) {
                if (count == 0) {
                    count++;
                    pre = i;
                }
                else {
                    printf("%d ", pre);
                    pre = i;
                    count++;
                }
            } 
        }
    }
    printf("%d\n", pre);
    printf("%d", count);
    return 0;
}
