/*************************************************************************
	> File Name: 11.HOJ440.cpp
	> Author:赵睿 
	> Mail: 1767153298@qq.com
	> Created Time: 2019年12月27日 星期五 15时33分39秒
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

void get_count(int i, int x, int *count) {
    while (i) {
        if (i % 10 == x) (*count)++;
        i /= 10;
    }
}

int main() {
    int n, x, count = 0;
    cin >> n >> x;
    for (int i = 1; i <= n; i++) get_count(i, x, &count);
    cout << count;
    return 0;
}
