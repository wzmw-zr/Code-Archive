/*************************************************************************
	> File Name: 1.LeetCode664.cpp
	> Author: 
	> Mail: 
	> Created Time: 2021年05月24日 星期一 00时02分42秒
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

int strangePrinter(string s) {
    int n = s.size();
    int dp[n][n];
    memset(dp, 0x3f, sizeof(dp));
    for (int i = 0; i < n; i++) 
        dp[i][i] = 1;
    for (int len = 2; len <= n; len++) {
        for (int i = 0; i + len - 1 < n; i++) {
            if (s[i] == s[i + len - 1])
                dp[i][i + len - 1] = dp[i][i + len - 2];
            for (int j = 1; j <= len - 1; j++) 
                dp[i][i + len - 1] = min(dp[i][i + len - 1], dp[i][i + j - 1] + dp[i + j][i + len - 1]);
        }
    }
    return dp[0][n - 1];
}

int main() {
    string s;
    cin >> s;
    cout << strangePrinter(s) << endl;
    return 0;
}
