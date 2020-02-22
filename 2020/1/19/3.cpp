/*************************************************************************
	> File Name: 3.cpp
	> Author:赵睿 
	> Mail: 1767153298@qq.com
	> Created Time: 2020年01月19日 星期日 16时08分58秒
 ************************************************************************/

#include<iostream>
#include<cstdio>
#include<string>
#include<cstring>
#include<cmath>
#include<cstdlib>
#include<cinttypes>
#include<cstdarg>
#include<algorithm>
#include<ctime>
#define max_n 10000
using namespace std;

int prime[max_n + 5] = {0};

void init() {
    for (int i = 2; i <= max_n; i++) {
        if (prime[i] == 0) prime[++prime[0]] = i;
        for (int j = 1; j <= prime[0] && i * prime[j] <= max_n; j++) {
            prime[i * prime[j]] = 1;
            if (i % prime[j] == 0) break;
        }
    }
}

int main() {
    init();
    for (int i = 1; i <= prime[0]; i++) cout << prime[i] << endl;
    return 0;
}
