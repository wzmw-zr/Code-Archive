/*************************************************************************
	> File Name: 2.LeetCode583.cpp
	> Author: 
	> Mail: 
	> Created Time: 2021年09月25日 星期六 08时37分17秒
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

int minDistance(string word1, string word2) {
    int n = word1.size(), m = word2.size();
    int dp[n + 1][m + 1];
    memset(dp, 0x3f, sizeof(dp));
    for (int i = 0; i <= n; i++) dp[i][0] = i;
    for (int i = 0; i <= m; i++) dp[0][i] = i;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (word1[i - 1] == word2[j - 1]) dp[i][j] = dp[i - 1][j - 1];
            else dp[i][j] = min(dp[i - 1][j], dp[i][j - 1]) + 1;
        }
    }
    return dp[n][m];
}

int main() {
    string word1;
    string word2;
    cin >> word1 >> word2;
    cout << minDistance(word1, word2) << endl;
    return 0;
}
