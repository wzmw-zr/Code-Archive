/*************************************************************************
	> File Name: prime_palindrome_number.cpp
	> Author: 
	> Mail: 
	> Created Time: 2019年11月27日 星期三 22时42分38秒
 ************************************************************************/

#include<iostream>
#include<cstdio>
#include<string>
using namespace std;

int main () {
    int a, b, pre = 0, flag = 0;
    scanf("%d%d", &a, &b);
    for (int i = a; i <= b; i++) {
        if (i % 10 == i / 10000 && (i % 100) / 10 == (i / 1000) % 10) {
            for (int j = 2; j <= i / 2; j++) {
                if (i % j == 0) {
                    flag = 1;
                    break;
                }
            }
            if (flag == 1) {
                flag = 0;
                continue;
            }else {
                if (pre != 0) {
                    printf("%d ", pre);
                    pre = i;
                }else pre = i;    
            }
        }
    }
    printf("%d", pre);
    return 0;
}
