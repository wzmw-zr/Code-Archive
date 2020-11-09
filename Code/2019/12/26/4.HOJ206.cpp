/*************************************************************************
	> File Name: 4.HOJ206.cpp
	> Author:赵睿 
	> Mail: 1767153298@qq.com
	> Created Time: 2019年12月26日 星期四 23时31分31秒
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

typedef struct arrow {
    double line[max_n + 5] = {0};
} Arrow;

Arrow a[max_n + 5];

void get_sum(int n, int m) {
    double sum = 0;
    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            sum += a[i].line[j];
        }
        i != m && cout << sum <<endl;
        i == m && cout << sum;
        sum = 0;
    }
}

int main() {
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cin >> a[j].line[i];
        }
    }
    get_sum(n, m);
    return 0;
}
