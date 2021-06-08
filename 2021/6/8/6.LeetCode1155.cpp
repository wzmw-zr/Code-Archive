/*************************************************************************
	> File Name: 6.LeetCode1155.cpp
	> Author: 
	> Mail: 
	> Created Time: 2021年06月08日 星期二 17时00分55秒
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

const int MOD = 1e9 + 7;

int numRollsToTarget(int d, int f, int target) {
    int dp[d + 1][target + 1];
    memset(dp, 0, sizeof(dp));
    dp[0][0] = 1;
    for (int i = 1; i <= d; i++) {
        for (int j = 1; j <= target; j++) {
            for (int k = 1; (k <= f) && (k <= j); k++) {
                dp[i][j] = (dp[i][j] + dp[i - 1][j - k]) % MOD;
            }
        }
    }
    return dp[d][target];
}

int main() {
    return 0;
}
