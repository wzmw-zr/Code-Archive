/*************************************************************************
	> File Name: 2.LeetCode1049.cpp
	> Author: 
	> Mail: 
	> Created Time: 2021年06月08日 星期二 00时20分01秒
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

// WA
int lastStoneWeightII(vector<int>& stones) {
    int n = stones.size();
    int dp[n][n];
    memset(dp, 0x3f, sizeof(dp));
    for (int i = 0; i < n; i++) dp[i][i] = stones[i];
    for (int len = 2; len <= n; len++) {
        for (int i = 0; i + len - 1 < n; i++) {
            for (int j = 1; j < len; j++) {
                dp[i][i + len - 1] = min(dp[i][i + len - 1], abs(dp[i][i + j - 1] - dp[i + j][i + len - 1]));
            }
        }
    }
    return dp[0][n - 1];
}

int main() {
    return 0;
}
