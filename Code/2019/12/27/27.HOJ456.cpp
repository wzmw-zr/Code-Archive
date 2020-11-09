/*************************************************************************
	> File Name: 27.HOJ456.cpp
	> Author:赵睿 
	> Mail: 1767153298@qq.com
	> Created Time: 2019年12月27日 星期五 18时45分50秒
 ************************************************************************/

#include<iostream>
#include<cstdio>
#include<string>
#include<cstring>
#include<cmath>
#include<inttypes.h>
#include<stdarg.h>
#include<algorithm>
#define max_n 1000000
using namespace std;

int len[max_n + 5] = {0};

int main() {
    int n, temp;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> temp;
        len[temp]++;
    }
    for (int i = 1; i <= max_n; i++) {
        if (!(len[i] & 1)) continue;
        cout << i;
        break;
    }
    return 0;
}
