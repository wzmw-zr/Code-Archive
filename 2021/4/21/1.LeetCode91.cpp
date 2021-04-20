/*************************************************************************
	> File Name: 1.LeetCode91.cpp
	> Author: 
	> Mail: 
	> Created Time: 2021年04月21日 星期三 00时02分23秒
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

int numDecodings(string s) {
    if (s[0] == '0') return 0;
    int n = s.size();
    int dp[n + 1];
    memset(dp, 0, sizeof(dp));
    dp[0] = 1;
    for (int i = 0; i < n; i++) {
        if (s[i] != '0') dp[i + 1] += dp[i];
        if (i >= 1 && s[i - 1] != '0') {
            int num = (s[i - 1] - '0') * 10 + s[i] - '0';
            if (num <= 26) dp[i + 1] += dp[i - 1];
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
