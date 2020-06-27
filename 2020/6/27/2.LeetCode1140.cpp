/*************************************************************************
	> File Name: 2.LeetCode1140.cpp
	> Author:赵睿 
	> Mail: 1767153298@qq.com
	> Created Time: 2020年06月27日 星期六 09时53分15秒
 ************************************************************************/

#include<iostream>
#include<string>
#include<cstring>
#include<cstdlib>
#include<vector>
#include<queue>
#include<stack>
#include<unordered_map>
#include<map>
#include<algorithm>
using namespace std;

int stoneGameII(vector<int>& piles) {
    int len = piles.size();
    int sum = 0;
    vector<vector<int>> dp(len + 1, vector<int>(len + 1, 0));
    for (int i = len - 1; i >= 0; i--) {
        sum += piles[i];
        for (int M = 1; M <= len; M++) {
            if (i + 2 * M >= len) {
                dp[i][M] = sum;
                continue;
            } 
            for (int x = 1; i + x <= len && x <= 2 * M; x++) {
                dp[i][M] = max(dp[i][M], sum - dp[i + x][max(M, x)]);
            }
        }
    }
    return dp[0][1];
}

int main() {

    return 0;
}
