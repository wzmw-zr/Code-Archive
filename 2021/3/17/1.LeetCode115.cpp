/*************************************************************************
	> File Name: 1.LeetCode115.cpp
	> Author: 
	> Mail: 
	> Created Time: 2021年03月17日 星期三 00时21分47秒
 ************************************************************************/

#include<iostream>
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

int numDistinct(string s, string t) {
    int n = s.size(), m = t.size();
    vector<vector<long>> dp(m + 1, vector<long>(n + 1, 0));
    for (int i = 0; i <= n; i++) dp[0][i] = 1;
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (t[i] != s[j]) dp[i + 1][j + 1] = dp[i + 1][j];
            else dp[i + 1][j + 1] = dp[i][j] + dp[i + 1][j];
        }
    }
    return dp[m][n];
}

int main() {
    string s, t;
    cin >> s >> t;
    cout << numDistinct(s, t) << endl;
    return 0;
}
