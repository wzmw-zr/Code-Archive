/*************************************************************************
	> File Name: 19.HOJ448.cpp
	> Author:赵睿 
	> Mail: 1767153298@qq.com
	> Created Time: 2019年12月27日 星期五 17时49分50秒
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

int number[max_n + 5] = {0};

int main() {
    int n, num, i;
    cin >> n;
    for (i = 1; i <= n; i++) cin >> number[i];
    cin >> num;
    for (i = 1; i <= n; i++) {
        if (number[i] != num) continue;
        cout << i;
        break;
    }
    i == n + 1 && cout << 0; 
    return 0;
}
