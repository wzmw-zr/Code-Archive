/*************************************************************************
	> File Name: 7.HZOJ559.cpp
	> Author:赵睿 
	> Mail: 1767153298@qq.com
	> Created Time: 2020年04月29日 星期三 18时23分00秒
 ************************************************************************/

#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
#define MAX_N 1000

struct data {
    double s, f;
} Data[MAX_N + 5];
int m, n;

int cmp(data a, data b) {
    return (a.s / a.f) > (b.s / b.f);
}

int main() {
    cin >> m >> n;
    for (int i = 0; i < n; i++) cin >> Data[i].s >> Data[i].f;
    sort(Data, Data + n, cmp);
    double val = 0;
    for (int i = 0; i < n && m; i++) {
        if (m  >= Data[i].f) {
            val += Data[i].s;
            m -= Data[i].f;
        } else {
            val += m * (Data[i].s / Data[i].f);
            m = 0;
        }
    }
    printf("%.3f\n", val);
    return 0;
}
