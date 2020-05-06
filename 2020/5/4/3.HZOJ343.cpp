/*************************************************************************
	> File Name: 3.HZOJ343.cpp
	> Author:赵睿 
	> Mail: 1767153298@qq.com
	> Created Time: 2020年05月04日 星期一 15时59分52秒
 ************************************************************************/

#include<iostream>
#include<cinttypes>
using namespace std;
#define MAX_N 3000

int n, ans;
int a[MAX_N + 5], b[MAX_N + 5];
int dp[MAX_N + 5];

int main() {    
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> a[i];
    for (int i = 1; i <= n; i++) cin >> b[i];
    for (int i = 1; i <= n; i++) {
        int tmp = 0;
        for (int j = 1; j <= n; j++) {
            if (a[i] > b[j]) tmp = max(tmp, dp[j]);
            if (a[i] == b[j]) dp[j] = tmp + 1;
        }
    }
    for (int i = 1; i <= n; i++) ans = max(ans, dp[i]);
    cout << ans << endl;
    return 0;
}
