/*************************************************************************
	> File Name: 7.large.mul.cpp
	> Author:赵睿 
	> Mail: 1767153298@qq.com
	> Created Time: 2019年12月21日 星期六 19时07分47秒
 ************************************************************************/

#include<iostream>
#include<cstdio>
#include<string>
#include<cstring>
#define max_n 100
using namespace std;

char str_a[max_n + 5], str_b[max_n + 5];
int a[max_n + 5], b[max_n + 5], c[2 * max_n + 5];

int main() {
    memset(c, 0, sizeof(c));
    scanf("%s%s", str_a, str_b);
    int len_a = strlen(str_a), len_b = strlen(str_b);
    for (int i = 0; i < len_a; i++) a[i] = str_a[len_a - i - 1] - '0';
    for (int i = 0; i < len_b; i++) b[i] = str_b[len_b - i - 1] - '0';
    for (int i = 0; i < len_a; i++) {
        for (int j = 0; j < len_b; j++) {
            c[i + j] += a[i] * b[j];
            if (c[i + j] >= 10) {
                c[i + j + 1] += c[i + j] / 10;
                c[i + j] %= 10;
            }
        }
    }
    int len_c = len_a + len_b;
    while (!c[len_c]) len_c--;
    for (int i = len_c; i >= 0; i--) {
        printf("%d", c[i]);
    }
    printf("\n");
    return 0;
}
