/*************************************************************************
	> File Name: count_a.cpp
	> Author: 
	> Mail: 
	> Created Time: 2019年11月27日 星期三 23时30分29秒
 ************************************************************************/

#include<iostream>
#include<cstdio>
#include<cstring>
#include<string>
using namespace std;

int main () {
    char s[101];
    int count = 0;
    //字符数组的名字实际上就是指针(地址)，直接使用该名称即可
    scanf("%s", s);
    int length = strlen(s);
    for (int i = 0; i < length; i++) {
        if (s[i] == 'A') count++;
    }
    printf("%d", count);
    return 0;
}
