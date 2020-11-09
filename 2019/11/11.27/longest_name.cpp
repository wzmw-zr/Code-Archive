/*************************************************************************
	> File Name: longest_name.cpp
	> Author: 
	> Mail: 
	> Created Time: 2019年11月27日 星期三 23时42分23秒
 ************************************************************************/

#include<iostream>
#include<cstdio>
#include<string>
#include<cstring>
using namespace std;

int main () {
    int n, length = 0;
    scanf("%d", &n);
    char s[101], result[101];
    for (int i = 1; i <= n; i++) {
        scanf("%s", s);
        int temp = strlen(s);
        if (temp > length) {
            length = temp;
            strcpy(result, s);
        }
    }
    printf("%s", result);
    return 0;
}
