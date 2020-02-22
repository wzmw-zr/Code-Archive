/*************************************************************************
	> File Name: 11.first.number.c
	> Author:赵睿 
	> Mail: 1767153298@qq.com
	> Created Time: 2020年02月20日 星期四 22时57分56秒
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define max_n 1000000

int main() {
    int n, number[max_n + 5] = {0}, num;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        scanf("%d", &num);
        if (num <= 0) continue ;
        number[num] = 1;
    }
    int i;
    for (i = 1; number[i]; i++);
    printf("%d\n", i);
    return 0;
}
