/*************************************************************************
	> File Name: 1.LeetCode1143.cpp
	> Author: 
	> Mail: 
	> Created Time: 2021年04月03日 星期六 00时03分21秒
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

int longestCommonSubsequence(string text1, string text2) {
    int n = text1.size(), m = text2.size();
    int dp[n + 1][m + 1];
    memset(dp, 0, sizeof(dp));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            dp[i + 1][j + 1] = max(dp[i][j + 1], dp[i + 1][j]);
            if (text1[i] == text2[j]) dp[i + 1][j + 1] = max(dp[i + 1][j + 1], dp[i][j] + 1);
        }
    }
    return dp[n][m];
}

int main() {
    string text1, text2;
    cin >> text1 >> text2;
    cout << longestCommonSubsequence(text1, text2) << endl;
    return 0;
}
