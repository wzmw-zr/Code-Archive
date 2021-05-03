/*************************************************************************
	> File Name: 2.LeetCode1473.cpp
	> Author: 
	> Mail: 
	> Created Time: 2021年05月04日 星期二 00时47分02秒
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

int minCost(vector<int>& houses, vector<vector<int>>& cost, int m, int n, int target) {
    bool check[m + 1][m + 1][n + 1];
    int prices[m + 1][m + 1][n + 1];
    memset(check, 0, sizeof(check));
    for (int i = 0; i <= m; i++) {
        for (int j = 0; j <= n; j++) {
            check[0][i][j] = true;
            prices[0][i][j] = 0;
        }
    }
    for (int i = 1; i <= m; i++) {
        for (int j = 0; j <= m; j++) {
            for (int k = 0; k <= n; k++) {
                prices[i][j][k] = INT32_MAX;
            }
        }
    }
    for (int i = 1; i <= m; i++) {
        if (houses[i - 1]) {
            if (i == 1) {
                check[1][1][houses[i - 1]] = true;
                prices[1][1][houses[i - 1]] = 0;
            } else {
                for (int j = 1; j <= i; j++) {
                    check[i][j][houses[i - 1]] |= check[i - 1][j][houses[i - 1]];
                    if (check[i - 1][j][houses[i - 1]]) {
                        prices[i][j][houses[i - 1]] = min(prices[i][j][houses[i - 1]], prices[i - 1][j][houses[i - 1]]);
                    }
                    for (int k = 1; k <= n; k++) {
                        if (k == houses[i - 1]) continue;
                        check[i][j][houses[i - 1]] |= check[i - 1][j - 1][k];
                        if (check[i - 1][j - 1][k]) {
                            prices[i][j][houses[i - 1]] = min(prices[i][j][houses[i - 1]], prices[i - 1][j - 1][k]);
                        }
                    }
                }
            }
        } else {
            if (i == 1) {
                for (int k = 1; k <= n; k++) {
                    check[1][1][k] = true;
                    prices[1][1][k] = cost[i - 1][k - 1];
                } 
            } else {
                for (int j = 1; j <= i; j++) {
                    for (int k = 1; k <= n; k++) {
                        check[i][j][k] |= check[i - 1][j][k];
                        if (check[i - 1][j][k]) {
                            prices[i][j][k] = min(prices[i][j][k], prices[i - 1][j][k] + cost[i - 1][k - 1]);
                        }
                        for (int t = 1; t <= n; t++) {
                            if (t == k) continue;
                            check[i][j][k] |= check[i - 1][j - 1][t];
                            if (check[i - 1][j - 1][t]) {
                                prices[i][j][k] = min(prices[i][j][k], prices[i - 1][j - 1][t] + cost[i - 1][k - 1]);
                            }
                        }
                    }
                }
            }
        }
    }
    int ans = INT32_MAX;
    for (int i = 1; i <= n; i++) ans = min(ans, prices[m][target][i]);
    return ans == INT32_MAX ? -1 : ans;
}

int main() {
    return 0;
}
