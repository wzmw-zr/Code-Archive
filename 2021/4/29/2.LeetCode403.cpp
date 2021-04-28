/*************************************************************************
	> File Name: 2.LeetCode403.cpp
	> Author: 
	> Mail: 
	> Created Time: 2021年04月29日 星期四 00时51分00秒
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

bool canCross(vector<int>& stones) {
    int n = stones.size();
    int dp[n + 1][n + 1];
    memset(dp, 0, sizeof(dp));
    dp[0][0] = 1;
    for (int i = 1; i < n; i++) {
        for (int j = i - 1; j >= 0; j--) {
            int k = stones[i] - stones[j];
            if (k > j + 1) break;
            dp[i][k] = dp[j][k - 1] | dp[j][k] | dp[j][k + 1];
        }
    }
    for (int i = 1; i < n; i++) {
        if (dp[n - 1][i]) return true;
    }
    return false;
}

int main() {
    return 0;
}
