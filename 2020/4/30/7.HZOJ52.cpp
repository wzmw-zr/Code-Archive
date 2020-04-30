/*************************************************************************
	> File Name: 7.HZOJ52.cpp
	> Author:赵睿 
	> Mail: 1767153298@qq.com
	> Created Time: 2020年04月30日 星期四 20时39分26秒
 ************************************************************************/

#include<iostream>
using namespace std;
#define MAX_N 1000000
#define INF 0x3f3f3f3f

long n, m;
long dp[MAX_N + 5], c[MAX_N + 5];

inline long S(long x) {
    return x * x;
}

int main() {
    cin >> n >> m;
    for (long i = 1; i <= n; i++) {
        cin >> c[i];
        c[i] += c[i - 1];
    }
    for (long i = 1; i <= n; i++) {
        dp[i] = dp[i - 1] + S(c[i] - c[i - 1]) + m;
        for (long j = 0; j < i - 1; j++) {
            dp[i] = min(dp[i], dp[j] + S(c[i] - c[j]) + m);
        }
    }
    cout << dp[n] << endl;
    return 0;
}
