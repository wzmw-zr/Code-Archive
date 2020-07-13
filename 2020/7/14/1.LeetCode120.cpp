/*************************************************************************
	> File Name: 1.LeetCode120.cpp
	> Author:赵睿 
	> Mail: 1767153298@qq.com
	> Created Time: 2020年07月14日 星期二 00时03分12秒
 ************************************************************************/

#include<iostream>
#include<cstdlib>
#include<cstring>
#include<string>
#include<vector>
#include<queue>
#include<stack>
#include<algorithm>
using namespace std;

int minimumTotal(vector<vector<int>>& triangle) {
    int n = triangle.size();
    vector<vector<int>> dp(n + 5, vector<int>(n + 5, 0));
    for (int i = 0; i < n; i++) dp[n - 1][i] = triangle[n - 1][i];
    for (int i = n - 1; i > 0; i--) {
        for (int j = 0; j < i; j++) {
            dp[i][j] = min(dp[i + 1][j], dp[i + 1][j + 1]) + triangle[i][j];
        }
    }
    return dp[0][0];
}

int main() {
    return 0;
}
