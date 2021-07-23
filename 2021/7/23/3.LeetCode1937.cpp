/*************************************************************************
	> File Name: 3.LeetCode1937.cpp
	> Author: 
	> Mail: 
	> Created Time: 2021年07月23日 星期五 08时48分44秒
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
    vector<vector<long long>> dp(m, vector<long long>(n, INT64_MIN));
    for (int i = 0; i < n; i++) dp[0][i] = points[0][i];
    for (int i = 1; i < m; i++) {
        long long mmax = dp[i - 1][0];
        for (int j = 0; j < n; j++) {
            mmax = max(mmax, dp[i - 1][j] + static_cast<long long>(j));
            dp[i][j] = max(dp[i][j], mmax + static_cast<long long>(points[i][j] - j));
        }
        mmax = dp[i - 1][n - 1] - static_cast<long long>(n - 1);
        for (int j = n - 1; j >= 0; j--) {
            mmax = max(mmax, dp[i - 1][j] - static_cast<long long>(j));
            dp[i][j] = max(dp[i][j], mmax + static_cast<long long>(points[i][j] + j));
        }
    }
    long long ans = INT64_MIN;
    for (int i = 0; i < n; i++) ans = max(ans, dp[m - 1][i]);
    return ans;
}

int main() {
    return 0;
}
