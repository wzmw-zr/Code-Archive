/*************************************************************************
	> File Name: 4.LeetCode10.cpp
	> Author: 
	> Mail: 
	> Created Time: 2021年03月26日 星期五 21时38分02秒
 ************************************************************************/

#include<iostream>
#include<cstdlib>
#include<cstring>
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

bool isMatch(string s, string p) {
    int n = s.size(), m = p.size();
    int dp[m + 1][n + 1];
    memset(dp, 0, sizeof(dp));
    dp[0][0] = 1;
    for (int i = 0; i < m; i++) if (p[i] == '*') dp[i + 1][0] = dp[i - 1][0];
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (p[i] == s[j] || p[i] == '.') {
                dp[i + 1][j + 1] |= dp[i][j];
                continue;
            }
            if (p[i] == '*') {
                if (p[i - 1] == s[j] || p[i - 1] == '.') {
                    dp[i + 1][j + 1] |= dp[i][j];
                    dp[i + 1][j + 1] |= dp[i + 1][j];
                }
                dp[i + 1][j + 1] |= dp[i - 1][j + 1];
                continue;
            }
            dp[i + 1][j + 1] = 0;
        }
    }
    for (int i = 0; i <= m; i++) {
        for (int j = 0; j <= n; j++) cout << dp[i][j] << " ";
        cout << endl;
    }
    return dp[m][n];
}

int main() {
    string s, p;
    cin >> s >> p;
    cout << (isMatch(s, p) ? "True" : "False") << endl;
    return 0;
}
