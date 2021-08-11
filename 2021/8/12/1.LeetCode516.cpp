/*************************************************************************
	> File Name: 1.LeetCode516.cpp
	> Author: 
	> Mail: 
	> Created Time: 2021年08月12日 星期四 00时02分52秒
 ************************************************************************/

#include <iostream>
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

int longestPalindromeSubseq(string s) {
    int n = s.size();
    vector<vector<int>> dp(n, vector<int>(n, 0));
    for (int i = 0; i < n; i++) dp[i][i] = 1;
    for (int i = 0; i < n - 1; i++) {
        if (s[i] == s[i + 1]) dp[i][i + 1] = 2;
    }
    for (int l = 3; l <= n; l++) {
        for (int i = 0; i < n - l + 1; i++) {
            if (s[i] != s[i + l - 1]) dp[i][i + l - 1] = max({dp[i + 1][i + l - 1], dp[i][i + l - 2]});
            else dp[i][i + l - 1] = max({dp[i + 1][i + l - 2] + 2, dp[i + 1][i + l - 1], dp[i][i + l - 2]});
        }
    }
    return dp[0][n - 1];
}

int main() {
    string s;
    cin >> s;
    cout << longestPalindromeSubseq(s) << endl;
    return 0;
}
