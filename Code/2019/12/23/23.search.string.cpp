/*************************************************************************
	> File Name: 23.search.string.cpp
	> Author:赵睿 
	> Mail: 1767153298@qq.com
	> Created Time: 2019年12月23日 星期一 18时58分10秒
 ************************************************************************/

#include<iostream>
#include<cstdio>
#include<string>
#include<cstring>
#include<math.h>
#include<inttypes.h>
#include<stdarg.h>
#define max_n 1000
using namespace std;

char a[max_n + 5] = {0}, b[max_n + 5] = {0};

int solve() {
    int len_1 = strlen(a), len_2 = strlen(b);
    int count = 0, flag = 0;
    for (int i = 0; i < len_1; i++) {
        for (int j = 0; j < len_2; j++) {
            if (a[i + j] == b[j]) continue;
            flag = 1;
            break;
        }
        if (!flag) count++;
        flag = 0;
    }
    return count;
}


int main() {
    char c;
    scanf("%[^\n]s", a);
    getchar();
    scanf("%[^\n]s", b);
    //printf("a = %s\n", a);
    //printf("b = %s\n", b);
    printf("%d", solve());
    return 0;
}
