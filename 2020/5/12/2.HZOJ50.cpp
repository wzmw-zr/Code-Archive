/*************************************************************************
	> File Name: 2.HZOJ50.cpp
	> Author:赵睿 
	> Mail: 1767153298@qq.com
	> Created Time: 2020年05月12日 星期二 18时54分32秒
 ************************************************************************/

#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<string>
using namespace std;
#define MAX_N 32
#define MAX_M 100000
long dp[MAX_N + 5][MAX_M + 5];

int main() {
    long n, m;
    cin >> n >> m;
    if (n == 1) {
        cout << m << endl;
        return 0;
    }
    for (long k = 1; k <= MAX_M; k++) dp[1][k] = k;
    for (long i = 2; i <= n; i++) {
        for (long k = 1; k <= MAX_M; k++) {
            dp[i][k] =  dp[i - 1][k - 1] + dp[i][k - 1] + 1;
        }
    }
    long p = 1;
    while (dp[n][p] < m) p++;
    cout << p << endl;
    return 0;
}
