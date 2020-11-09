/*************************************************************************
	> File Name: output_char_diamond.cpp
	> Author: 
	> Mail: 
	> Created Time: 2019年11月27日 星期三 20时52分21秒
 ************************************************************************/

#include<iostream>
#include<cstdio>
#include<string>
using namespace std;

int main () {
    int n;
    scanf("%d", &n);
    char c = 'A';
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n - i; j++) printf(" ");
        for (int j = 1; j <= 2 * i - 1; j++) printf("%c", c);
        printf("\n");
        c += 1;
    }
    c -= 1;
    for (int i = 1; i <= n - 1; i++) {
        c -= 1;
        for (int j = 1; j <= i; j++) printf(" ");
        for (int j = 1; j <= 2 * (n - i) - 1; j++) printf("%c", c);
        printf("\n");
    }
    return 0;
}
