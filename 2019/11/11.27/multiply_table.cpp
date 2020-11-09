/*************************************************************************
	> File Name: multiply_table.cpp
	> Author: 
	> Mail: 
	> Created Time: 2019年11月27日 星期三 19时25分57秒
 ************************************************************************/

#include<iostream>
#include<cstdio>
#include<string>
using namespace std;

int main () {
    int n;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        for (int j = i; j <= n - 1; j++) {
            printf("%d*%d=%d\t", i, j, i * j);
        }
        printf("%d*%d=%d\n", i, n, i * n);
    }
    return 0;
}
