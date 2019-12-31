/*************************************************************************
	> File Name: 2.int.16.cpp
	> Author: 
	> Mail: 
	> Created Time: 2019年12月12日 星期四 20时29分34秒
 ************************************************************************/

#include<iostream>
#include<cstdio>
#include<string>
#include<cstring>
using namespace std;

void test_sscanf() {
    char str[] = "123 456 789 987";
    int a, b, c, d;
    sscanf(str ,"%d%[^$]s", &a, str);
}

int main () {
    int n, count = 0;
    char str[100];
    scanf("%d", &n);
    sprintf(str, "%x", n);
    printf("%d", strlen(str));
    return 0;
}
