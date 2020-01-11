/*************************************************************************
	> File Name: 1.HOJ521.cpp
	> Author:赵睿 
	> Mail: 1767153298@qq.com
	> Created Time: 2020年01月03日 星期五 07时39分05秒
 ************************************************************************/

#include<iostream>
#include<cstdio>
#include<string>
#include<cstring>
#include<cmath>
#include<cstdlib>
#include<inttypes.h>
#include<stdarg.h>
#include<algorithm>
#include<ctime>
#define max_n 100000
using namespace std;

int prime[max_n + 5] = {0};
int is_prime[max_n + 5] = {0};
int num[35] = {0};

void init() {
    for (int i = 2; i <= max_n; i++) {
        if (is_prime[i] == 0) prime[++prime[0]] = 1;
        for (int j = 1; j <= prime[0] && i * prime[j] <= max_n; j++) {
            is_prime[i * prime[j]] = 1;
            if (i % prime[j] == 0) break;
        }
    }
}

int main() {
    init();
    //int n, r;
    //cin >> n >> r;
    //for (int i = 1; i <= n; i++) cin >> num[i];
    return 0;
}
