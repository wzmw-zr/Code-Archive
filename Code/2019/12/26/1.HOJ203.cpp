/*************************************************************************
	> File Name: 1.HOJ203.cpp
	> Author:赵睿 
	> Mail: 1767153298@qq.com
	> Created Time: 2019年12月26日 星期四 22时24分57秒
 ************************************************************************/

#include<iostream>
#include<cstdio>
#include<string>
#include<cstring>
#include<cmath>
#include<inttypes.h>
#include<stdarg.h>
#include<algorithm>
#define max_n 10
using namespace std;

typedef struct arrow {
    int height[max_n + 5] = {0};
} Arrow;

Arrow a[max_n + 5];

int height[max_n + 5][max_n + 5] = {0};

int temp[(max_n + 5) * (max_n + 5)] = {0};

void get_highest(int m, int n) {
    for (int i = 1; i <= n; i++) {
        sort(a[i].height + 1, a[i].height + m + 1);
        cout << a[i].height[m] << endl;
    }
}

void get_all(int m, int n) {
    int cnt = 0;
    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            temp[cnt++] = height[i][j]; 
        }
    }
    sort(temp, temp + n * m);
    for (int i = n * m - 1; i >= 0; i--) {
        i  && cout << temp[i] << " ";
        !i && cout << temp[i] << endl;
    }
}

int get_avg(int m, int n) {
    double sum = 0;
    for (int i = 0; i < n * m; i++) {
        sum += temp[i] * 1.0;
    }
    double avg = sum / (m * n * 1.0);
    if (avg - floor(avg) < 0.5) return (int) floor(avg);
    return (int) ceil(avg);
}


void get_ht_avg(int m, int n, int avg) {
    int count = 0;
    for (int i = 0; i < n * m; i++) {
        if (temp[i] >= avg) count++;
    } 
    cout << count <<endl;
}

int main() {
    int m, n;
    cin >> m >> n;
    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            cin >> height[i][j];
            a[j].height[i] = height[i][j];
        }
    }
    get_highest(m, n);
    get_all(m, n);
    int avg = get_avg(m, n);
    cout << avg << endl;
    get_ht_avg(m, n, avg);
    return 0;
}
