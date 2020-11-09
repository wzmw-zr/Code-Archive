/*************************************************************************
	> File Name: 22.HOJ451.cpp
	> Author:赵睿 
	> Mail: 1767153298@qq.com
	> Created Time: 2019年12月27日 星期五 18时06分44秒
 ************************************************************************/

#include<iostream>
#include<cstdio>
#include<string>
#include<cstring>
#include<cmath>
#include<inttypes.h>
#include<stdarg.h>
#include<algorithm>
#define max_n 100000
using namespace std;

int goods[max_n + 5] = {0};

int main() {
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> goods[i];
    sort(goods + 1, goods + n + 1);
    for (int i = 1; i <= n; i++) {
        i == n && cout << goods[i];
        i != n && cout << goods[i] << endl;
    }
    return 0;
}
