/*************************************************************************
	> File Name: 1.cube_sum.c
	> Author:赵睿 
	> Mail: 1767153298@qq.com
	> Created Time: 2020年05月30日 星期六 07时54分16秒
 ************************************************************************/

#include<stdio.h>

int main() {
    int n, sum = 0;
    printf("please input number between 1 and 100 : ");
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) sum += i * i * i;
    printf("sum = %d\n", sum);
    return 0;
}
