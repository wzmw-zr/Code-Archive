/*************************************************************************
	> File Name: 2.LeetCode650.cpp
	> Author: 
	> Mail: 
	> Created Time: 2021年09月19日 星期日 09时14分30秒
 ************************************************************************/

#include <iostream>
#include <string>
#include <vector>
#include <cmath>
using namespace std;

int minSteps(int n) {
    vector<int> dp(n + 1, INT32_MAX);
    dp[1] = 0;
    for (int i = 2; i <= n; i++) {
        for (int j = 1; j * j <= i; j++) {
            if (i % j) continue;
            dp[i] = min(dp[i], dp[j] + i / j);
            dp[i] = min(dp[i], dp[i / j] + j);
        }
    }
    return dp[n];
}

int main() {
    int n;
    cin >> n;
    cout << minSteps(n) << endl;
    return 0;
}
