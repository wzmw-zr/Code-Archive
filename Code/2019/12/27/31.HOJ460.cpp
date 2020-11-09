/*************************************************************************
	> File Name: 31.HOJ460.cpp
	> Author:赵睿 
	> Mail: 1767153298@qq.com
	> Created Time: 2019年12月27日 星期五 19时40分23秒
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

int num[max_n + 5] = {0};

int main() {
    int n, k, count, index = 1, temp = 1;
    cin >> n >> k;
    count = n;
    while (count > 1) {
        if (temp % k) {
            index++;
            temp++;
        } else if (num[index % k]) {
            index++;
        } else {
            num[index] = 1;
            count--;
            index++;
            temp++;
        }
        if (index > n) index = 1;
    }
    for (int i = 1; i <= n; i++) {
        !num[i] && cout << i << endl;
    }
    return 0;
}
