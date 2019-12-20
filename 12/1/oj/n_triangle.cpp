/*************************************************************************
	> File Name: n_triangle.cpp
	> Author: 
	> Mail: 
	> Created Time: 2019年12月01日 星期日 19时03分48秒
 ************************************************************************/

#include<iostream>
#include<cstdio>
using namespace std;

int main () {
    int n;
    scanf("%d", &n);
    for (int i = n; i > 0; i--) {
        for (int j = i; j > 1; j--) {
            printf("%d ", j);
        }
        printf("%d\n", 1);
    }
    return 0;
}
