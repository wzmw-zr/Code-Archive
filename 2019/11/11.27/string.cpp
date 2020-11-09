/*************************************************************************
	> File Name: string.cpp
	> Author: 
	> Mail: 
	> Created Time: 2019年11月27日 星期三 23时49分50秒
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
    for (int i = 0; i < length; i++) {
        if (s[i] >= 'A' && s[i] <= 'Z') {
            if (s[i] == 'Z') s[i] = 'A';
            else s[i] += 1;
        }
        if (s[i] >= 'a' && s[i] <= 'z') {
            if (s[i] == 'z') s[i] = 'a';
            else s[i] += 1;
        }
    }
    printf("%s", s);
    return 0;
}
