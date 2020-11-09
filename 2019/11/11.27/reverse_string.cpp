/*************************************************************************
	> File Name: reverse_string.cpp
	> Author: 
	> Mail: 
	> Created Time: 2019年11月28日 星期四 00时43分03秒
 ************************************************************************/

#include<iostream>
#include<cstdio>
#include<string>
#include<cstring>
using namespace std;

int main () {
    char s[50];
    scanf("%s", s);
    int length = strlen(s);
    for(int i = length - 1; i >= 0; i--) printf("%c", s[i]);
    return 0;
}
