/*************************************************************************
	> File Name: 7.case.c
	> Author:赵睿 
	> Mail: 1767153298@qq.com
	> Created Time: 2020年02月18日 星期二 19时58分00秒
 ************************************************************************/

#include<stdio.h>

int main() {
    int n = 10;
    for (int i = 1; i <= n; i += 2) {
        printf("i = %d, n = %d\n", i, n++);
    }
}
