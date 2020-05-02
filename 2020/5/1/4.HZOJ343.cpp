/*************************************************************************
	> File Name: 4.HZOJ343.cpp
	> Author:赵睿 
	> Mail: 1767153298@qq.com
	> Created Time: 2020年05月01日 星期五 19时56分52秒
 ************************************************************************/

#include<iostream>
using namespace std;
#define MAX_N 3000
#define INF 0x3f3f3f3f

long n;
long a[MAX_N + 5], b[MAX_N + 5];
long dp[MAX_N + 5][MAX_N + 5], len[MAX_N + 5];

long bs(long l, long r, long data) {
    if (l == r) {
        cout << len[l] << endl;
        return l;
    }
    long mid = (l + r + 1) >> 1;
    if (len[mid] < data) return bs(mid, r, data);
    return bs(l, mid - 1, data);
}

int main() {
    cin >> n;
    for (long i = 1; i <= n; i++) cin >> a[i];
    for (long i = 1; i <= n; i++) cin >> b[i];
    for (long i = 0; i <= n; i++) len[i] = INF;
    for (long i = 1; i <= n; i++) {
        for (long j = 1; j <= n; j++) {
            cout << "a[i] = " << a[i] << ", b[j] = " << b[j] << endl;
            if (a[i] == b[j]) {
                long l = bs(0, n, a[i]);
                cout << "a[i] = " << a[i] << ", len = " << l + 1 << endl;
                if (len[l] != INF && a[i] > len[l]) {
                    dp[i][j] = l + 1;
                    len[l + 1] = min(a[i], len[l + 1]);
                } else {
                    dp[i][j] = l;
                    len[l] = a[i];
                }
            } else {
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]); 
            }
        }
    }
    cout << dp[n][n] << endl;
    return 0;
}
