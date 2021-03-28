/*************************************************************************
	> File Name: 1.LeetCode343.cpp
	> Author: 
	> Mail: 
	> Created Time: 2021年03月29日 星期一 00时07分00秒
 ************************************************************************/

#include<iostream>
#include<cstring>
#include<cstdlib>
using namespace std;

int integerBreak(int n) {
    int dp[n + 1];
    memset(dp, 0, sizeof(dp));
    dp[1] = dp[2] = 1;
    for (int i = 3; i <= n; i++) {
        for (int j = 1; j < i; j++) {
            dp[i] = max(dp[i], max(j, dp[j]) * max(i - j, dp[i - j]));
        }
    }
    return dp[n];
}

int main() {
    int n;
    cin >> n;
    cout << integerBreak(n) << endl;
    return 0;
}
