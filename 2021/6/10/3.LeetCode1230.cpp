/*************************************************************************
	> File Name: 3.LeetCode1230.cpp
	> Author: 
	> Mail: 
	> Created Time: 2021年06月10日 星期四 00时38分02秒
 ************************************************************************/

#include <iostream>
#include <cstring>
#include <cstdlib>
#include <string>
#include <vector>
using namespace std;

double probabilityOfHeads(vector<double>& prob, int target) {
    int n = prob.size();
    vector<vector<double>> dp(n + 1, vector<double>(target + 1, 0.0));
    dp[0][0] = 1.0;
    for (int i = 1; i <= n; i++) {
        dp[i][0] = dp[i - 1][0] * (1 - prob[i - 1]);
        for (int j = 1; j <= min(i, target); j++) {
            dp[i][j] = dp[i - 1][j] * (1 - prob[i - 1]) + dp[i - 1][j - 1] * prob[i - 1];
        }
    }
    return dp[n][target];
}

int main() {
    return 0;
}
