/*************************************************************************
	> File Name: 2.LeetCode877.cpp
	> Author: 
	> Mail: 
	> Created Time: 2020年12月14日 星期一 08时57分24秒
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

bool stoneGame(vector<int>& piles) {
    int n = piles.size();
    int dp[n + 1][n + 1];
    int pre[n + 1];
    memset(dp, 0, sizeof(dp));
    memset(pre, 0, sizeof(pre));
    for (int i = 1; i <= n; i++) pre[i] = pre[i - 1] + piles[i - 1];
    for (int i = 1; i <= n; i++) dp[i][i] = piles[i - 1];
    for (int i = 2; i <= n; i++) {
        for (int j = 1; j + i - 1 <= n; j++) {
            dp[j][j + i - 1] = max(piles[j - 1] - dp[j + 1][j + i - 1], piles[j + i - 2] - dp[j][j + i - 2]);
        }
    }
    return dp[1][n] > 0;
}

int main() {
    return 0;
}
