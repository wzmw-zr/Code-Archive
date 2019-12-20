/*************************************************************************
	> File Name: 2.cpp
	> Author: 
	> Mail: 
	> Created Time: 2019年12月01日 星期日 15时53分16秒
 ************************************************************************/

#include<iostream>
#include<cstdio>
#include<string>
#include<cstring>
using namespace std;

int main () {
    int count = 0;
    char c;
    while (scanf("%c", &c) != EOF && c != '\n') {
        count++;
    }
    printf("%d", count);
    return 0;
}


/*

