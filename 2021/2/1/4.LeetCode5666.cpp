/*************************************************************************
	> File Name: 4.LeetCode5666.cpp
	> Author: 
	> Mail: 
	> Created Time: 2021年02月01日 星期一 01时54分39秒
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

bool checkPartitioning(string s) {
    int n = s.size();
    int dp[n][n];
    memset(dp, 0, sizeof(dp));
    for (int i = 0; i < n; i++) dp[i][i] = 1;
    for (int i = 0; i < n - 1; i++) {
        if (s[i + 1] == s[i]) dp[i][i + 1] = 1;
    }
    for (int i = 3; i <= n; i++) {
        for (int j = 0; j + i - 1 < n; j++) {
            dp[j][j + i - 1] = s[j] == s[j + i - 1] ? dp[j + 1][j + i - 2] : 0;
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (dp[0][i] && dp[i + 1][j] && dp[j + 1][n - 1]) return true;
        }
    }
    return false;
}

int main() {
    string s;
    cin >> s;
    cout << (checkPartitioning(s) ? "True" : "False") << endl;
    return 0;
}
