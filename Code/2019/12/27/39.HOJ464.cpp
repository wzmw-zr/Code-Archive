/*************************************************************************
	> File Name: 39.HOJ464.cpp
	> Author:赵睿 
	> Mail: 1767153298@qq.com
	> Created Time: 2019年12月27日 星期五 21时39分00秒
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

int is_val(int n) {
    if (n % 4 == 0 && n % 100 != 0) return 1;
    else if (n % 400 == 0 ) return 1;
    else return 0;
}

int main() {
    int x, y, count = 0;
    cin >> x >> y;
    for (int i = x; i <= y; i++) {
        is_val(i) && (count++);
    }
    cout << count;
    return 0;
}
