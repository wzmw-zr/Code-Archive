/*************************************************************************
	> File Name: 1.cpp
	> Author: 
	> Mail: 
	> Created Time: 2019年12月01日 星期日 15时28分22秒
 ************************************************************************/

#include<iostream>
#include<cstdio>
using namespace std;

int main () {
    int n ,count = 0;
    scanf("%d", &n);

    while (n != 0) {
        n /= 10;
        count++;
    }
    printf("%d", count);
    return 0;
}
