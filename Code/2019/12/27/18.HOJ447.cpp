/*************************************************************************
	> File Name: 18.HOJ447.cpp
	> Author:赵睿 
	> Mail: 1767153298@qq.com
	> Created Time: 2019年12月27日 星期五 17时42分01秒
 ************************************************************************/

#include<iostream>
#include<cstdio>
#include<string>
#include<cstring>
#include<cmath>
#include<inttypes.h>
#include<stdarg.h>
#include<algorithm>
#define max_n 1000
using namespace std;

int lucky[max_n + 5] = {0};

int is_value(int n) {
    while (n) {
        if (n % 10 == 4 || n % 10 == 7) {
            n /= 10;
        }else return 0;
    }
    return 1;
}

int main() {
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        if (!is_value(i)) continue;
        lucky[++lucky[0]] = i;
    }
    for (int i = 1; i <= lucky[0]; i++) {
        if (n % lucky[i]) continue;
        cout << "YES";
        return 0;
    }
    cout << "NO";
    return 0;
}
