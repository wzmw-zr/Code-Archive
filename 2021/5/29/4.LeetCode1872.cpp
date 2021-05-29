/*************************************************************************
	> File Name: 4.LeetCode1872.cpp
	> Author: 
	> Mail: 
	> Created Time: 2021年05月29日 星期六 20时37分42秒
 ************************************************************************/

#include<iostream>
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

int stoneGameVIII(vector<int> &stones) {
    int n = stones.size();
    vector<int> pre(n + 1, 0);
    vector<int> dp(n + 2, 0);
    for (int i = 0; i < n; i++)
        pre[i + 1] = pre[i] + stones[i];
    dp[n] = pre[n];
    int mmax = max(0, dp[n]);
    for (int i = n - 1; i >= 2; i--) {
        dp[i] = max(dp[i + 1], pre[i] - dp[i + 1]);
    }
    return dp[2];
}

int main() {
    return 0;
}
