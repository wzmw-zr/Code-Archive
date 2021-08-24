/*************************************************************************
	> File Name: 2.LeetCode787.cpp
	> Author: 
	> Mail: 
	> Created Time: 2021年08月24日 星期二 10时55分03秒
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

int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
    int dp[n + 5][k + 5];
    memset(dp, 0x3f, sizeof(dp));
    dp[src][0] = 0;
    for (int i = 1; i <= k + 1; i++) {
        for (auto x : flights) {
            dp[x[1]][i] = min({dp[x[1]][i - 1], dp[x[1]][i], dp[x[0]][i - 1] + x[2]});
        }
    }
    return dp[dst][k + 1] == 0x3f3f3f3f ? -1 : dp[dst][k + 1];
}

int main() {
    return 0;
}
