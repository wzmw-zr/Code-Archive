/*************************************************************************
	> File Name: 3.LeetCode1691.cpp
	> Author: 
	> Mail: 
	> Created Time: 2020年12月14日 星期一 09时15分37秒
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

int stoneGameVII(vector<int>& stones) {
    int n = stones.size();
    int dp[n + 1][n + 1];
    int pre[n + 1];
    memset(dp, 0, sizeof(dp));
    memset(pre, 0, sizeof(pre));
    for (int i = 1; i <= n; i++) pre[i] = pre[i - 1] + stones[i - 1];
    for (int i = 2; i <= n; i++) {
        for (int j = 1; j + i - 1 <= n; j++) {
            dp[j][j + i - 1] = max(pre[j + i - 1] - pre[j] - dp[j + 1][j + i - 1], pre[j + i - 2] - pre[j - 1] - dp[j][j + i - 2]);
        }
    }
    return dp[1][n];
}

int main() {
    return 0;
}
