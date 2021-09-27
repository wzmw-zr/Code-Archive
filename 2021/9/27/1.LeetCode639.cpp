/*************************************************************************
	> File Name: 1.LeetCode639.cpp
	> Author: 
	> Mail: 
	> Created Time: 2021年09月27日 星期一 09时56分49秒
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
    long dp[n + 1];
    memset(dp, 0, sizeof(dp));
    dp[0] = 1;
    dp[1] = s[0] == '*' ? 9 : 1;
    for (int i = 1; i < n; i++) {
        if (s[i] == '*') {
            if (s[i - 1] == '*') dp[i + 1] = (dp[i] * 9 + dp[i - 1] * 17) % MOD;
            else if (s[i - 1] == '1') dp[i + 1] = (dp[i] * 9 + dp[i - 1] * 9) % MOD;
            else if (s[i - 1] == '2') dp[i + 1] = (dp[i] * 9 + dp[i - 1] * 6) % MOD;
            else dp[i + 1] = (dp[i] * 9) % MOD;
        } else if (s[i] == '0') {
            if (s[i - 1] == '*') dp[i + 1] = (dp[i - 1] * 2) % MOD;
            else dp[i + 1] = dp[i - 1];
        } else if (s[i] <= '6') {
            if (s[i - 1] == '*') dp[i + 1] = (dp[i] + dp[i - 1] * 2) % MOD;
            else if (s[i - 1] == '1' || s[i - 1] == '2') dp[i + 1] = (dp[i] + dp[i - 1]) % MOD;
            else dp[i + 1] = dp[i];
        } else {
            if (s[i - 1] == '*' || s[i - 1] == '1') dp[i + 1] = (dp[i] + dp[i - 1]) % MOD;
            else dp[i + 1] = dp[i];
        }
    }
    return dp[n];
}

int main() {
    string s;
    cin >> s;
    cout << numDecodings(s) << endl;
    return 0;
}
