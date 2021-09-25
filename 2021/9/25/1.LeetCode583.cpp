/*************************************************************************
	> File Name: 1.LeetCode583.cpp
	> Author: 
	> Mail: 
	> Created Time: 2021年09月25日 星期六 08时24分20秒
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
    memset(dp, 0, sizeof(dp));
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            if (word1[i - 1] == word2[j - 1]) dp[i][j] = max(dp[i][j], dp[i - 1][j - 1] + 1);
        }
    }
    return n + m - 2 * dp[n][m];
}

int main() {
    string word1;
    string word2;
    cin >> word1 >> word2;
    cout << minDistance(word1, word2) << endl;
    return 0;
}
