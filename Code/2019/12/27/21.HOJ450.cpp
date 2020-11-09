/*************************************************************************
	> File Name: 21.HOJ450.cpp
	> Author:赵睿 
	> Mail: 1767153298@qq.com
	> Created Time: 2019年12月27日 星期五 18时01分02秒
 ************************************************************************/

#include<iostream>
#include<cstdio>
#include<string>
#include<cstring>
#include<cmath>
#include<inttypes.h>
#include<stdarg.h>
#include<algorithm>
#define max_n 100
using namespace std;

int height[max_n + 5] = {0};

int main() {
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> height[i];
    }
    sort(height + 1, height + n + 1);
    for (int i = 1; i <= n; i++) {
        i == n && cout << height[i];
        i != n && cout << height[i] << " ";
    }
    return 0;
}
