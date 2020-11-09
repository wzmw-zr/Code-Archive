/*************************************************************************
	> File Name: 10.HOJ439.cpp
	> Author:赵睿 
	> Mail: 1767153298@qq.com
	> Created Time: 2019年12月27日 星期五 15时28分55秒
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

int main() {
    double x, len = 2, all = 0;
    int count = 0;
    cin >> x;
    while (all < x) {
        all += len;
        len *= 0.98; 
        count++;
    }
    cout << count;
    return 0;
}
