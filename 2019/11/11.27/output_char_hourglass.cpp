/*************************************************************************
	> File Name: output_char_hourglass.cpp
	> Author: 
	> Mail: 
	> Created Time: 2019年11月27日 星期三 21时02分27秒
 ************************************************************************/

#include<iostream>
#include<cstdio>
#include<string>
using namespace std;

int main () {
    int n;
    scanf("%d", &n);
    char c = 'A';
    for (int i = 0; i <= n; i++) {
        for (int j = 0; j < i ; j++) printf(" ");
        for (int j = i; j <= n; j++){
            printf("%c", c + j);
        }
        for (int j = n - 1; j >= i; j--){
            printf("%c", c + j);
        }
        printf("\n");
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 0; j <= n - i - 1; j++) printf(" ");
        for (int j = n - i; j <= n; j++) printf("%c", c + j);
        for (int j = n - 1; j >= n - i; j--) printf("%c", c + j);
        printf("\n");
    }
    return 0;
}
