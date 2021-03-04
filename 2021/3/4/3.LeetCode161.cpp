/*************************************************************************
	> File Name: 3.LeetCode161.cpp
	> Author: 
	> Mail: 
	> Created Time: 2021年03月04日 星期四 16时12分15秒
 ************************************************************************/

#include<iostream>
#include<cstring>
#include<cstdlib>
#include<string>
#include<vector>
using namespace std;

bool isOneEditDistance(string s, string t) {
    int len1 = s.size(), len2 = t.size();
    int dp[len1 + 1][len2 + 2];
    memset(dp, 0, sizeof(dp));
    for (int i = 0; i <= len2; i++) dp[0][i] = i;
    for (int i = 0; i <= len1; i++) dp[i][0] = i;
    for (int i = 1; i <= len1; i++) {
        for (int j = 1; j <= len2; j++) {
            if (s[i - 1] == t[j - 1]) dp[i][j] = min(dp[i - 1][j - 1], min(dp[i - 1][j], dp[i][j - 1]) + 1);
            else dp[i][j] = min(dp[i - 1][j - 1], min(dp[i][j - 1], dp[i - 1][j])) + 1;
        }
    }
    return dp[len1][len2] == 1;
}

int main() {
    return 0;
}
