/*************************************************************************
	> File Name: 11.EP47.cpp
	> Author:赵睿 
	> Mail: 1767153298@qq.com
	> Created Time: 2019年12月29日 星期日 18时05分51秒
 ************************************************************************/

#include<iostream>
#include<cstdio>
#include<string>
#include<cstring>
#include<cstdlib>
#include<inttypes.h>
#include<stdarg.h>
#include<algorithm>
#define max_n 1000000
using namespace std;

int prime[max_n + 5] = {0};

void init() {
    for (int i = 2; i <= max_n; i++) {
        if (prime[i]) continue;
        for (int j = i; j <= max_n; j += i) prime[j] += 1;
    }
    return ;
}

int main() {
    init();
    int ans = 0;
    for (int i = 1000; i <= max_n; i++) {
        int flag = 1;
        for (int j = 0; j < 4 && flag; j++) {
            flag = (prime[i + j] == 4);
        }
        if (!flag) continue;
        ans = i;
        break;
    }
    cout << ans << endl;
    return 0;
}


