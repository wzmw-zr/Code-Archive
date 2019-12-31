/*************************************************************************
	> File Name: 22.up.low.reverse.cpp
	> Author:赵睿 
	> Mail: 1767153298@qq.com
	> Created Time: 2019年12月23日 星期一 18时47分44秒
 ************************************************************************/

#include<iostream>
#include<cstdio>
#include<string>
#include<cstring>
#include<math.h>
#include<inttypes.h>
#include<stdarg.h>
#define max_n 10000000
using namespace std;

char s[max_n + 5] = {0};

void solve() {
    for (int i = 0; i < strlen(s); i++) {
        if (s[i] - 'a' >= 0) s[i] -= 32;
        else s[i] += 32;
    }
    printf("%s", s);
}

int main() {
    scanf("%s", s);
    solve();
    return 0;
}
