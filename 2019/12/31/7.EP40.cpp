/*************************************************************************
	> File Name: 7.EP40.cpp
	> Author:赵睿 
	> Mail: 1767153298@qq.com
	> Created Time: 2019年12月31日 星期二 18时28分32秒
 ************************************************************************/

#include<iostream>
#include<cstdio>
#include<string>
#include<cstring>
#include<cmath>
#include<cstdlib>
#include<inttypes.h>
#include<stdarg.h>
#include<algorithm>
using namespace std;

int get_val(int n) {
    if (n <= 9) return n;
    n -= 10;
    int cur = 10, j = 2, num;
    while (n >= j * 9 * cur) {
        n -= j * 9 * cur;
        cur *= 10;
        j++;
    }
    num = n / j + cur;
    for (int i = 0; i < j - n % j - 1; i++) num /= 10;
    return num % 10;
}

int main() {
    int result = 1, p = 1;
    for (int i = 0; i < 7; i++) {
        result *= get_val(p);
        cout << get_val(p) << endl;
        p *= 10;
    }
    cout << result << endl;
    return 0;
}
