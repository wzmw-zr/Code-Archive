/*************************************************************************
	> File Name: 2.777.cpp
	> Author:赵睿 
	> Mail: 1767153298@qq.com
	> Created Time: 2020年09月26日 星期六 15时31分22秒
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

long caculate(int ind) {
    long ans = 0, len = strlen(n + ind);
    printf("%s\n", n + ind);
    if (len == 1) {
        if (n[ind] >= '7') return 1;
        return 0;
    }
    ans += (n[ind] - '0') * dp[len - ind - 1];
    ans %= MOD;
    if (n[ind] < '7') {
        ans = (ans + caculate(ind + 1)) % MOD;
    } else if (n[ind] == '7') {
        ans = (ans + last_sum[ind + 1] + 1) % MOD;
        ans = (ans + caculate(ind + 1)) % MOD;
    } else {
        ans = (ans + ten_pow[len - ind - 1]) % MOD;
        ans = (ans + caculate(ind + 1)) % MOD;
    }
    return ans;
}


int main() {
    init();
    scanf("%d", &t);
    while (t--) {
        memset(n, 0, sizeof(n));
        memset(last_sum, 0, sizeof(last_sum));
        scanf("%s", n);
        //printf("%s\n", n);
        int len = strlen(n);
        for (int i = len - 1; i >= 0; i--) last_sum[i] = (last_sum[i + 1] + (n[i] - '0') * ten_pow[len - i - 1]) % MOD;
        //for (int i = len - 1; i >= 0; i--) printf("%d ", last_sum[i]);
        //printf("\n");
        cout << caculate(0) << endl;
    }
    return 0;
}
