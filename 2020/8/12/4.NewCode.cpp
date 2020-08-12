/*************************************************************************
	> File Name: 4.NewCode.cpp
	> Author:赵睿 
	> Mail: 1767153298@qq.com
	> Created Time: 2020年08月12日 星期三 20时24分15秒
 ************************************************************************/

#include<iostream>
#include<cstdlib>
#include<cstring>
using namespace std;
#define MAX_N 100000

int n;
int com[MAX_N + 5], exec[MAX_N + 5];
int dp[MAX_N + 5][3];

int main() {
    cin >> n;
    memset(dp, 0x3f, sizeof(dp));
    for (int i = 1; i <= n; i++) cin >> com[i];
    for (int i = 1; i <= n; i++) cin >> exec[i];
    if (com[1]) dp[1][0] = 0;
    if (exec[1]) dp[1][1] = 0;
    dp[1][2] = 1;
    cout << dp[1][0] << " " << dp[1][1] << " " << dp[1][2] << endl;
    for (int i = 2; i <= n; i++) {
        if (com[i]) dp[i][0] = min(dp[i - 1][1], dp[i - 1][2]);
        if (exec[i]) dp[i][1] = min(dp[i - 1][0], dp[i - 1][2]);
        dp[i][2] = min(dp[i - 1][0], min(dp[i - 1][1], dp[i - 1][2])) + 1;
        cout << dp[i][0] << " " << dp[i][1] << " " <<  dp[i][2] << endl;
    }
    cout << min(dp[n][0], min(dp[n][1], dp[n][2])) << endl;
    return 0;
}
