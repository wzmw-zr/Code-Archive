/*************************************************************************
	> File Name: 3.HOZJ52.cpp
	> Author:赵睿 
	> Mail: 1767153298@qq.com
	> Created Time: 2020年05月01日 星期五 18时55分19秒
 ************************************************************************/

#include<iostream>
using namespace std;
#define MAX_N 1000000

#define SQ(a) ((a) * (a))

long n, m;
long c[MAX_N + 5], dp[MAX_N + 5], f[MAX_N + 5];
int q[MAX_N + 5], head, tail = 1;

void set(int i, int j) {
    dp[i] = dp[j] + SQ(c[i] - c[j]) + m;
    f[i] = dp[i] + SQ(c[i]);
}

double slope(int i, int j) {
    return 1.0 * (f[i] - f[j]) / (c[i] - c[j]);
}

int main() {
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        cin >> c[i];
        c[i] += c[i - 1];
    }
    for (int i = 1; i <= n; i++) {
        while (tail - head >= 2 && slope(q[head], q[head + 1]) < 2 * c[i]) ++head;
        set(i, q[head]);
        while (tail - head >= 2 && slope(q[tail - 1], q[tail - 2]) > slope(q[tail - 1], i)) --tail;
        q[tail++] = i;
    }
    cout << dp[n] << endl;
    return 0;
}
