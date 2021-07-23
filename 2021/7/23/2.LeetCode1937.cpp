/*************************************************************************
	> File Name: 2.LeetCode1937.cpp
	> Author: 
	> Mail: 
	> Created Time: 2021年07月23日 星期五 08时14分04秒
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

long long maxPoints(vector<vector<int>>& points) {
    int m = points.size(), n = points[0].size();
    long long dp[m][n];
    memset(dp, 0, sizeof(dp));
    for (int i = 0; i < n; i++) dp[0][i] = points[0][i];
    for (int i = 1; i < m; i++) {
        for (int j = 0; j < n; j++) {
            long long mmax = INT64_MIN;
            for (int k = 0; k < n; k++) mmax = max(mmax, dp[i - 1][k] + points[i][j] - abs(j - k));
            dp[i][j] = mmax;
        }
    }
    long long ans = INT64_MIN;
    for (int i = 0; i < n; i++) ans = max(ans, dp[m - 1][i]);
    return ans;
}

int main() {
    return 0;
}
