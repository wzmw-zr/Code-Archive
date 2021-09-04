/*************************************************************************
	> File Name: 1.LeetCode2037.cpp
	> Author: 
	> Mail: 
	> Created Time: 2021年09月04日 星期六 08时10分12秒
 ************************************************************************/

#include <iostream>
#include <string>
#include <vector>
using namespace std;

const int MOD = 1e9 + 7;

int fib(int n) {
    vector<int> dp(n + 2, 0);
    dp[1] = 1;
    for (int i = 2; i <= n; i++) dp[i] = (dp[i - 1] + dp[i - 2]) % MOD;
    return dp[n];
}

int main() {
    return 0;
}
