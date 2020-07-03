/*************************************************************************
	> File Name: 1.LeetCode32.cpp
	> Author:赵睿 
	> Mail: 1767153298@qq.com
	> Created Time: 2020年07月04日 星期六 00时20分40秒
 ************************************************************************/

#include<iostream>
#include<cstdlib>
#include<cstring>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;

int longestValidParentheses(string s) {
    int s_len = s.size(), res = 0;
    int dp[s_len + 5][s_len + 5];
    memset(dp, 0, sizeof(dp));

    for (int i = 0; i < s_len; i++) dp[i][i - 1] = 1;

    for (int i = 2; i <= s_len; i += 2) {
        for (int j = 0; j <= s_len - i; j++) {
            if (s[j] == '(' && s[j + i - 1] == ')') {
                //cout << j << " " << j + i - 1 << endl;
                for (int k = 2; k <= i; k += 2) {
                    if (dp[j][j + k - 1] && dp[j + k][j + i - 1]) {
                        //cout << k << endl;
                        res = i;
                        dp[j][j + i - 1] = 1;
                        break;
                    }
                }
                if (dp[j + 1][j + i - 2]) {
                    res = i;
                    dp[j][j + i - 1] = 1; 
                }
            }
        }
    }
    return res;
}

int main() {
    string s;
    cin >> s;
    cout << longestValidParentheses(s) << endl;
    return 0;
}
