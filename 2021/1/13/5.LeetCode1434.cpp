/*************************************************************************
	> File Name: 5.LeetCode1434.cpp
	> Author: 
	> Mail: 
	> Created Time: 2021年01月13日 星期三 10时44分54秒
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

const int MOD = 1000000007;

int numberWays(vector<vector<int>>& hats) {
    int n = hats.size();
    int dp[41][(1 << n)];
    int like[n][41];
    memset(dp, 0, sizeof(dp));
    memset(like, 0, sizeof(like));
    for (int i = 0; i < n; i++) {
        for (int &x : hats[i]) like[i][x] = 1;
    }

    dp[0][0] = 1;
    for (int i = 1; i <= 40; i++) {
        for (int j = 0; j < (1 << n); j++) {
            dp[i][j] += dp[i - 1][j];
            for (int k = 0; k < n; k++) {
                if ((j & (1 << k)) && (like[k][i])) {
                    dp[i][j] += dp[i - 1][j & ~(1 << k)];
                    dp[i][j] %= MOD;
                } 
            }
        }
    }
    return dp[40][(1 << n) - 1];
}

int main() {
    return 0;
}
