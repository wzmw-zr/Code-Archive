/*************************************************************************
	> File Name: 2.LeetCode639.cpp
	> Author: 
	> Mail: 
	> Created Time: 2021年09月27日 星期一 16时21分25秒
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

// WA
const long MOD = 1e9 + 7;

int numDecodings(string s) {
    int n = s.size();
    long dp[n + 1][27];
    memset(dp, 0, sizeof(dp));
    for (int i = 1; i <= 26; i++) dp[0][i] = 1;
    if (s[0] == '*') {
        for (int i = 1; i <= 9; i++) dp[1][i] = 1;
    } else dp[1][s[0] - '0'] = 1;
    
    for (int i = 1; i < n; i++) {
        if (s[i] == '*') {
            long sum = 0;
            for (int j = 1; j <= 26; j++) sum = (sum + dp[i][j]) % MOD;
            for (int j = 1; j <= 9; j++) dp[i + 1][j] = (dp[i + 1][j] + sum) % MOD;
            long t = 0;
            for (int j = 1; j <= 26; j++) t = (t + dp[i - 1][j]) % MOD;
            if (s[i - 1] == '*' || s[i - 1] == '1') {
                for (int j = 11; j <= 19; j++) dp[i + 1][j] = (dp[i + 1][j] + t) % MOD;
            }
            if (s[i - 1] == '*' || s[i - 1] == '2') {
                for (int j = 21; j <= 26; j++) dp[i + 1][j] = (dp[i + 1][j] + t) % MOD;
            }
        } else if (s[i] == '0') {
            long t = 0;
            for (int j = 1; j <= 26; j++) t = (t + dp[i - 1][j]) % MOD;
            if (s[i - 1] == '*' || s[i - 1] == '1') dp[i + 1][10] = (dp[i + 1][10] + t) % MOD;
            if (s[i - 1] == '*' || s[i - 1] == '2') dp[i + 1][20] = (dp[i + 1][20] + t) % MOD;
        } else if (s[i] <= '6') {
            long sum = 0;
            for (int j = 1; j <= 26; j++) sum = (sum + dp[i][j]) % MOD;
            dp[i + 1][s[i] - '0'] = (dp[i + 1][s[i] - '0'] + sum) % MOD;
            long t = 0;
            for (int j = 1; j <= 26; j++) t = (t + dp[i - 1][j]) % MOD;
            if (s[i - 1] == '*' || s[i - 1] == '1') dp[i + 1][10 + s[i] - '0'] = (t + dp[i + 1][10 + s[i] - '0']) % MOD;
            if (s[i - 1] == '*' || s[i - 1] == '2') dp[i + 1][20 + s[i] - '0'] = (t + dp[i + 1][20 + s[i] - '0']) % MOD;
        } else {
            long sum = 0;
            for (int j = 1; j <= 26; j++) sum = (sum + dp[i][j]) % MOD;
            dp[i + 1][s[i] - '0'] = (dp[i + 1][s[i] - '0'] + sum) % MOD;
        }
    }
    long ans = 0;
    for (int i = 1; i <= 26; i++) ans = (ans + dp[n][i]) % MOD;
    return ans;
}

int main() {
    string s;
    cin >> s;
    cout << numDecodings(s) << endl;
    return 0;
}
