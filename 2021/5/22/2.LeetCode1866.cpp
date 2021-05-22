/*************************************************************************
	> File Name: 2.LeetCode1866.cpp
	> Author: 
	> Mail: 
	> Created Time: 2021年05月22日 星期六 14时48分25秒
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
#include<unordered_map>
#include<unordered_set>
#include<algorithm>
using namespace std;

const long MOD = 1e9 + 7;

int rearrangeSticks(int n, int k) {
    long dp[n + 1][k + 1];
    memset(dp, 0, sizeof(dp));
    dp[0][0] = 1;
    for (int i = 1; i <= k; i++) {
        for (int j = 1; j <= n; j++) 
            dp[j][i] = (dp[j - 1][i - 1] + ((j - 1) * dp[j - 1][i] % MOD)) % MOD;
    }
    return dp[n][k];
}

int main() {
    int n, k;
    cin >> n >> k;
    cout << rearrangeSticks(n, k) << endl;
    return 0;
}
