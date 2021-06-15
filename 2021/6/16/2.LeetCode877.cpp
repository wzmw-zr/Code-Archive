/*************************************************************************
	> File Name: 2.LeetCode877.cpp
	> Author: 
	> Mail: 
	> Created Time: 2021年06月16日 星期三 00时11分58秒
 ************************************************************************/

#include <iostream>
#include <cstring>
#include <vector>
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

bool stoneGame(vector<int>& piles) {
    int n = piles.size();
    int dp[n][n];
    memset(dp, 0, sizeof(dp));
    for (int i = 0; i < n; i++) dp[i][i] = piles[i];
    for (int l = 2; l <= n; l++) {
        for (int i = 0; i + l - 1 < n; i++) {
            dp[i][i + l - 1] = max(piles[i] - dp[i + 1][i + l - 1], piles[i + l - 1] - dp[i][i + l - 2]);
        }
    }
    return dp[0][n - 1] > 0;
}

int main() {
    return 0;
}
