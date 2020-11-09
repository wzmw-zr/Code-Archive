/*************************************************************************
	> File Name: output_a_diamond.cpp
	> Author: 
	> Mail: 
	> Created Time: 2019年11月27日 星期三 20时38分37秒
 ************************************************************************/

#include<iostream>
#include<cstdio>
#include<string>
using namespace std;

int main () {
    int n;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n - i; j++) printf(" ");
        for (int j = 1; j <= 2 * i; j++) printf("A");
        printf("\n");
    }
    for (int i = n - 1; i >= 1; i-- ) {
        for (int j = 1; j <= n - i; j++) printf(" ");
        for (int j = 1; j <= 2 * i; j++) printf("A");
        printf("\n");
    }
    return 0;
}
