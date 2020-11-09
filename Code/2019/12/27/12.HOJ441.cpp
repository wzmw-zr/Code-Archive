/*************************************************************************
	> File Name: 12.HOJ441.cpp
	> Author:赵睿 
	> Mail: 1767153298@qq.com
	> Created Time: 2019年12月27日 星期五 15时37分56秒
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
    int x, n, count = 0;
    cin >> x >> n;
    for (int i = x; i < x + n; i++) {
        if (i % 7 && i % 7 != 6) count += 2;
    }
    cout << count;
    return 0;
}
