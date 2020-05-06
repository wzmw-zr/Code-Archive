/*************************************************************************
	> File Name: 4.HZOJ343.cpp
	> Author:赵睿 
	> Mail: 1767153298@qq.com
	> Created Time: 2020年05月04日 星期一 19时20分37秒
 ************************************************************************/

#include<iostream>
using namespace std;
#define MAX_N 3000

int n, ans;
int a[MAX_N + 5], b[MAX_N + 5];
int dp[MAX_N + 5][MAX_N + 5];

int main() {
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> a[i];
    for (int i = 1; i <= n; i++) cin >> b[i];
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            dp[i][j] = dp[i - 1][j];
            if (a[i] == b[j]) {
                dp[i][j] = max(dp[i][j], 1);
                for (int k = 1; k < j; k++) {
                    if (b[k] < b[j]) dp[i][j] = max(dp[i][j], dp[i - 1][k] + 1);
                }
            }
        }
    }
    for (int i = 1; i <= n; i++) ans = max(ans, dp[n][i]);
    cout << ans << endl;
    return 0;
}
