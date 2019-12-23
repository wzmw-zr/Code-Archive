/*************************************************************************
	> File Name: 5.a.pow.b.cpp
	> Author:赵睿 
	> Mail: 1767153298@qq.com
	> Created Time: 2019年12月21日 星期六 16时30分56秒
 ************************************************************************/

#include<iostream>
#include<cstdio>
#include<string>
#include<cstring>
using namespace std;


int main() {
    int a, b;
    scanf("%d%d", &a, &b);
    char mul[1000] = {0};
    int x = a, digit = 0;
    while (x) {
        x /= 10;
        digit++;
    }
    mul[0] = digit;
    mul[1] = 1;
    for (int i = 1; i <= b; i++) {
        for (int j = 1; j <= mul[0]; j++) {
            mul[j] *= a;
        }
        for (int j = 1; j <= mul[0]; j++) {
            if (mul[j] < 10) continue;
            mul[j + 1] += mul[j] /10;
            mul[j] %= 10;
            mul[0] += (j == mul[0]);
        }
    }
    for (int i = mul[0]; i > 0; i--) {
        printf("%d", mul[i]);
    }
    printf("\n");
    return 0;
}
