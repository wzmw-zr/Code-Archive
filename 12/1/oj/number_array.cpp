/*************************************************************************
	> File Name: number_array.cpp
	> Author: 
	> Mail: 
	> Created Time: 2019年12月01日 星期日 19时40分08秒
 ************************************************************************/

#include<iostream>
#include<cstdio>
using namespace std;

int main () {
    int n, offset = 0, start = 3, sum = 0;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        printf("%d\n", start);
        offset += 2;
        sum += start;
        start += offset;
    }
    printf("%d", sum);
    return 0;
}
