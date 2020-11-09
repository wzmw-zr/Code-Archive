/*************************************************************************
	> File Name: 26.HOJ455.cpp
	> Author:赵睿 
	> Mail: 1767153298@qq.com
	> Created Time: 2019年12月27日 星期五 18时39分55秒
 ************************************************************************/

#include<iostream>
#include<cstdio>
#include<string>
#include<cstring>
#include<cmath>
#include<inttypes.h>
#include<stdarg.h>
#include<algorithm>
using namespace std;

int gcd(int a, int b) {
    return b ? gcd(b, a % b) : a;
}

int main() {
    int len[5] = {0};
    for (int i = 1; i <= 3; i++) cin >> len[i];
    sort(len + 1, len + 4);
    int factor = gcd(len[1], len[3]);
    cout << len[1] / factor << "/" << len[3] / factor;
    return 0;
}
