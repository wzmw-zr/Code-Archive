/*************************************************************************
	> File Name: char_triangle.cpp
	> Author: 
	> Mail: 
	> Created Time: 2019年11月27日 星期三 20时29分13秒
 ************************************************************************/

#include<iostream>
#include<cstdio>
#include<string>
using namespace std;

int main () {
    int n;
    scanf("%d", &n);
    char c = 'A' - 1;
    for (int i = n; i >= 1; i--) {
        for (int j = 1; j <= i; j++) {
            c += 1;
            printf("%c", c);
        }
        printf("\n");
    }
    return 0;
}
