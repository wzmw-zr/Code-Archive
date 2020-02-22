/*************************************************************************
	> File Name: 7.magic.machine.c
	> Author:赵睿 
	> Mail: 1767153298@qq.com
	> Created Time: 2020年02月13日 星期四 22时43分40秒
 ************************************************************************/

#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define max_n 100

int main() {
    int n, numbers[max_n + 5] = {0};
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) scanf("%d", &numbers[i]);
    for (int i = 1; i < n; i++) {
        if (numbers[i] - numbers[i + 1] < 2) continue;
        printf("NO\n");
        return 0;
    }
    printf("YES\n");
    return 0;
}
