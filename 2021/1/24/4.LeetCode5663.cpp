/*************************************************************************
	> File Name: 4.LeetCode5663.cpp
	> Author: 
	> Mail: 
	> Created Time: 2021年01月24日 星期日 10时38分55秒
 ************************************************************************/

#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;

int kthLargestValue(vector<vector<int>>& matrix, int k) {
    int m = matrix.size();
    int n = matrix[0].size();
    vector<vector<int>> dp(m, vector<int>(n, 0));
    vector<int> ans;
    dp[0][0] = matrix[0][0];
    for (int i = 1; i < n; i++) dp[0][i] = dp[0][i - 1] ^ matrix[0][i];
    for (int i = 1; i < m; i++) dp[i][0] = dp[i - 1][0] ^ matrix[i][0];
    for (int i = 1; i < m; i++) {
        for (int j = 1; j < n; j++) dp[i][j] = dp[i - 1][j] ^ dp[i][j - 1] ^ dp[i - 1][j - 1] ^ matrix[i][j];
    }
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) ans.push_back(dp[i][j]);
    }
    sort(ans.begin(), ans.end(), [](int a, int b){ return a > b; });
    return ans[k - 1];
}

int main() {
    return 0;
}
