/*************************************************************************
	> File Name: 28.HOJ457.cpp
	> Author:赵睿 
	> Mail: 1767153298@qq.com
	> Created Time: 2019年12月27日 星期五 18时51分04秒
 ************************************************************************/

#include<iostream>
#include<cstdio>
#include<string>
#include<cstring>
#include<cmath>
#include<stdlib.h>
#include<inttypes.h>
#include<stdarg.h>
#include<algorithm>
#define max_n 1000
using namespace std;

int num[max_n + 5] = {0};
int check[max_n + 5] = {0};

int main() {
    int n, i;
    cin >> n;
    for (i = 1; i <= n; i++) cin >> num[i];
    for (i = 1; i < n; i++) check[abs(num[i] - num[i + 1])] = 1;
    for (i = 1; i < n; i++) {
        if(check[i]) continue;
        cout << "Not jolly";
        break;
    }
    i == n && cout << "Jolly";
    return 0;
}
