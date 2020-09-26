/*************************************************************************
	> File Name: 3.777.cpp
	> Author:赵睿 
	> Mail: 1767153298@qq.com
	> Created Time: 2020年09月26日 星期六 16时41分18秒
 ************************************************************************/

#include<iostream>
#include<cstring>
#include<cstdlib>
#include<string>
#include<vector>
#include<queue>
#include<stack>
#include<map>
#include<set>
#include<algorithm>
using namespace std;

#define MAX_M 100010
#define MOD 1000000007

long t;
char n[MAX_M + 10];
long dp[MAX_M + 5];
long ten_pow[MAX_M + 5];
long last_sum[MAX_M + 5];

void init() {
    dp[1] = 1;
    ten_pow[0] = 1;
    ten_pow[1] = 10;
    for (int i = 2; i < MAX_M; i++) {
        ten_pow[i] = (ten_pow[i - 1] * 10) % MOD;
        dp[i] = (ten_pow[i - 1] + 10 * dp[i - 1]) % MOD;
    }
    //for (int i = 0; i < 20; i++) cout << ten_pow[i] << " ";
    //cout << endl;
}

int main() {
    init();
    scanf("%d", &t);
    while (t--) {
        memset(n, 0, sizeof(n));
        memset(last_sum, 0, sizeof(last_sum));
        scanf("%s", n + 1);
        int len = strlen(n + 1);
        for (int i = 1, j = len; i <= j; i++, j--) {
            swap(n[i], n[j]);
        }
        long ans = 0;
        for (int i = 1; i <= len; i++) {
            last_sum[i] = (last_sum[i - 1] + (n[i] - '0') * ten_pow[i - 1]) % MOD;  
            ans = (ans + (n[i] - '0') * dp[i - 1]) % MOD;
            if (n[i] < '7') {
                continue;
            } else if (n[i] == '7') {
                ans = (ans + last_sum[i - 1] + 1) % MOD;
            } else {
                ans = (ans + ten_pow[i - 1]) % MOD;
            }
        } 
        cout << ans << endl;
    }
    return 0;
}

