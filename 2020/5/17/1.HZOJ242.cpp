/*************************************************************************
	> File Name: 1.HZOJ242.cpp
	> Author:赵睿 
	> Mail: 1767153298@qq.com
	> Created Time: 2020年05月17日 星期日 15时58分48秒
 ************************************************************************/

#include<iostream>
#include<cstdio>
#include<cstdlib>
using namespace std;
#define MAX_N 100000
#define INF 0x3f3f3f3f

long a[MAX_N + 5], b[MAX_N + 5], sum[MAX_N + 5];
long n, m;

bool check(long A) {
    for (long i = 1; i <= n; i++) {
        b[i] = a[i] - A;
        sum[i] = b[i] + sum[i - 1];
    }
    long Y = 0;
    for (long j = m; j <= n; j++) {
        Y = min(Y, sum[j - m]);
        if (sum[j] >= Y) return true;
    }
    return false;
}

long bs(long l, long r) {
    if (l == r) return l;
    long mid = (l + r + 1) >> 1;
    if (check(mid)) return bs(mid, r);
    return bs(l, mid - 1);
}

int main() {
    cin >> n >> m;
    long l = INF, r = -INF;
    for (long i = 1; i <= n; i++) {
        cin >> a[i];
        a[i] *= 1000;
        l = min(l, a[i]);
        r = max(l, a[i]);
    }
    cout << bs(l, r) << endl;
    return 0;
}
