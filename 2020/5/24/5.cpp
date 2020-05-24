/*************************************************************************
	> File Name: 5.cpp
	> Author:赵睿 
	> Mail: 1767153298@qq.com
	> Created Time: 2020年05月24日 星期日 19时14分30秒
 ************************************************************************/

#include<iostream>
using namespace std;
#define MAX_N 10000
#define MAX_M 20

long m, n;
int a[MAX_M + 5];
long dp[MAX_M + 5][MAX_N + 5]; 

int main() {
    cin >> m >> n;
    for (int i = 1; i <= m; i++) cin >> a[i];
    for (int i = 0; i <= m; i++) dp[i][0] = 1;
    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            if (j < a[i]) dp[i][j] = dp[i - 1][j];
            else dp[i][j] = dp[i - 1][j] + dp[i][j - a[i]];
            dp[i][j] %= 9973;
        }
    }
    cout << dp[m][n] << endl;
    return 0;
}
