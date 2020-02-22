/*************************************************************************
	> File Name: 3.test.cpp
	> Author:赵睿 
	> Mail: 1767153298@qq.com
	> Created Time: 2020年01月11日 星期六 16时21分11秒
 ************************************************************************/

#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;

int main() {
    char str[1000];
    scanf("%[^\n]s", str);
    int len = strlen(str);
    for (int i = 0; str[i]; i++) {
        if (str[i] == ' ') str[i] = '\n';
    }
    printf("%s", str);
    return 0;
}
