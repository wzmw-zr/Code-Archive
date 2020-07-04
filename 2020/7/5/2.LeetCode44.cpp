/*************************************************************************
	> File Name: 2.LeetCode44.cpp
	> Author:赵睿 
	> Mail: 1767153298@qq.com
	> Created Time: 2020年07月05日 星期日 00时42分58秒
 ************************************************************************/

#include<iostream>
#include<cstdlib>
#include<cstring>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;

bool isMatch(string s, string p) {
    int s_len = s.size(), p_len = p.size();

    int dp[s_len + 5][p_len + 5];
    memset(dp, 0, sizeof(dp));

    dp[0][0] = 1;

    for (int i = 1; i <= p_len; i++) {
        if (p[i - 1] == '*') dp[0][i] = 1;
        else break;
    }

    for (int i = 1; i <= s_len; i++) {
        for (int j = 1; j <= p_len; j++) {
            if (p[j - 1] == '*') dp[i][j] = dp[i - 1][j] | dp[i][j - 1];
            else if (p[j - 1] == '?') dp[i][j] = dp[i - 1][j - 1];
            else if (p[j - 1] == s[i - 1]) dp[i][j] = dp[i - 1][j - 1];
        }
    }

    return dp[s_len][p_len];
}

int main() {
    string s, p;
    cin >> s >> p;
    cout << (isMatch(s, p) ? "True" : "False") << endl;
    return 0;
}
