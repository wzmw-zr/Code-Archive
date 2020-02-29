/*************************************************************************
	> File Name: 2.case.cpp
	> Author:赵睿 
	> Mail: 1767153298@qq.com
	> Created Time: 2020年02月29日 星期六 09时23分36秒
 ************************************************************************/

#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
using namespace std;

int main() {
    char *s = (char *) calloc(sizeof(char), 100);
    sprintf(s, "[]");
    int len = strlen(s);
    s[len - 1] = '\0';
    s += 1;
    char *res;
    res = strtok(s, ",");
    while (res) {
        printf("res = %s\n", res);
        res = strtok(NULL, ",");
    }
    return 0;
}
