/*************************************************************************
	> File Name: 5.e.cpp
	> Author:赵睿 
	> Mail: 1767153298@qq.com
	> Created Time: 2020年05月30日 星期六 15时13分16秒
 ************************************************************************/

#include<iostream>
using namespace std;
#define MAX_N 3000

long n, ans;
long a[MAX_N + 5], b[MAX_N + 5];
long dp[MAX_N + 5][MAX_N + 5];

int main() {
    cin >> n;
    for (long i = 1; i <= n; i++) cin >> a[i];
    for (long i = 1; i <= n; i++) cin >> b[i];
    for (long i = 1; i <= n; i++) {
        for (long j = 1; j <= n; j++) {
            dp[i][j] = dp[i - 1][j];
            if (a[i] == b[j]) {
                dp[i][j] = dp[i][j] > 1 ? dp[i][j] : 1;
                for (long k = 1; k < j; k++) {
                    if (b[k] < b[j]) dp[i][j] = max(dp[i][j], dp[i - 1][k] + 1);
                }
            }
        }
    }
    for (long i = 1; i <= n; i++) ans = max(ans, dp[n][i]);
    cout << ans << endl;
    return 0;
}
