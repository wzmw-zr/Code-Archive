/*************************************************************************
	> File Name: 9.case.c
	> Author:赵睿 
	> Mail: 1767153298@qq.com
	> Created Time: 2020年01月28日 星期二 21时44分03秒
 ************************************************************************/

#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<sys/wait.h>

int main() {
    int n;
    scanf("%d", &n);
    int *a = (int *) malloc(sizeof(int) * 2 * (n + 5));
    for (int i = 1; i <= n; i++) a[i] = i;
    for (int i = 1; i <= n; i++) printf("%d ", a[i]);
    printf("\n");
    return 0;
}
