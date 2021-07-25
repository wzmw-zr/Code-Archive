/*************************************************************************
	> File Name: 1.LeetCode1713.cpp
	> Author: 
	> Mail: 
	> Created Time: 2021年07月26日 星期一 00时06分05秒
 ************************************************************************/

#include <iostream>
#include <cstring>
#include <cstdlib>
#include <string>
#include <vector>
#include <queue>
#include <stack>
#include <map>
#include <set>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>
using namespace std;

// TLE
int minOperations(vector<int>& target, vector<int>& arr) {
    int n = target.size(), m = arr.size();
    int dp[n + 1][m + 1];
    memset(dp, 0, sizeof(dp));
    for (int i = 0; i <= n; i++) dp[i][0] = i;
    for (int j = 1; j <= m; j++) {
        for (int i = 1; i <= n; i++) {
            if (target[i - 1] == arr[j - 1]) dp[i][j] = dp[i - 1][j - 1];
            else dp[i][j] = min(dp[i - 1][j] + 1, dp[i][j - 1]);
        }
    }
    return dp[n][m];
}

int main() {
    return 0;
}
