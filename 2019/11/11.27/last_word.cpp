/*************************************************************************
	> File Name: last_word.cpp
	> Author: 
	> Mail: 
	> Created Time: 2019年11月28日 星期四 00时46分18秒
 ************************************************************************/

#include<iostream>
#include<cstdio>
#include<string>
#include<cstring>
using namespace std;

int main () {
    char s[50];
    int count = 0;
    while(scanf("%s", s) != EOF) {
        count = 0;
        int length = strlen(s);
        for (int i = length - 1; i >= 0; i--) {
            if (s[i] == ' ') break;
            else count++;
        }
    }
    printf("%d", count);
    return 0;
}
