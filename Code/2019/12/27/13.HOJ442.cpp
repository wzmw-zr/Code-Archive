/*************************************************************************
	> File Name: 13.HOJ442.cpp
	> Author:赵睿 
	> Mail: 1767153298@qq.com
	> Created Time: 2019年12月27日 星期五 15时47分12秒
 ************************************************************************/

#include<iostream>
#include<cstdio>
#include<string>
#include<cstring>
#include<cmath>
#include<inttypes.h>
#include<stdarg.h>
#include<algorithm>
#define max_n 30
using namespace std;

int number[max_n + 5] = {0};

int main() {
    int n;
    cin >> n;
    number[0] = 1, number[1] = 1;
    for (int i = 2; i <= n; i++) number[i] = number[i - 1] + number[i - 2];
    for (int i = 1; i <= n; i++) {
        i == n && cout << number[i];
        i != n && cout << number[i] << " ";
    }
    return 0;
}
