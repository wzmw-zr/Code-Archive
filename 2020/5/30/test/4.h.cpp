/*************************************************************************
	> File Name: 4.h.cpp
	> Author:赵睿 
	> Mail: 1767153298@qq.com
	> Created Time: 2020年05月30日 星期六 14时57分57秒
 ************************************************************************/

#include<iostream>
using namespace std;
#define MAX_M 20
#define MAX_N 10000

long m, n;
long num[MAX_M + 5];
long dp[MAX_M + 5][MAX_N + 5];

int main() {
    cin >> m >> n;
    for (long i = 1; i <= m; i++) cin >> num[i];
    for (long i = 0; i <= MAX_M; i++) dp[i][0] = 1;
    for (long i = 1; i <= m; i++) {
        for (long j = 1; j <= n; j++) {
            if (j < num[i]) dp[i][j] = dp[i - 1][j] % 9973;
            else dp[i][j] = (dp[i - 1][j] + dp[i][j - num[i]]) % 9973;
        }
    }
    cout << dp[m][n] << endl;
    return 0;
}
