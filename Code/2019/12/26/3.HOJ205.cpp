/*************************************************************************
	> File Name: 3.HOJ205.cpp
	> Author:赵睿 
	> Mail: 1767153298@qq.com
	> Created Time: 2019年12月26日 星期四 23时20分01秒
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

typedef struct line {
    int arrow[max_n + 5] = {0};
} Line;

Line l[max_n + 5];

void get_avg(int n, int m) {
    double sum = 0;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            sum += l[i].arrow[j] * 1.0;
        }
        i != n && printf("%.6lf\n", sum / m);
        i == n && printf("%.6lf", sum / m);
        sum = 0;
    }
}

int main() {
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) cin >> l[i].arrow[j];
    }
    get_avg(n, m);
    return 0;
}
