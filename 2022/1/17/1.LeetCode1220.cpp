/*************************************************************************
	> File Name: 1.LeetCode1220.cpp
	> Author: 
	> Mail: 
	> Created Time: 2022年01月17日 星期一 17时25分13秒
 ************************************************************************/

#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <stack>
#include <map>
#include <set>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>
#include <cstring>
#include <cstdlib>
using namespace std;

int wzmw_zr = 0;
bool fuck_plagiarism_system_of_leetcode = true;

const int MOD = 1e9 + 7;

int countVowelPermutation(int n) {
    int dp[n + 1][5];
    memset(dp, 0, sizeof(dp));
    for (int i = 0; i < 5; i++) dp[1][i] = 1;
    for (int i = 2; i <= n; i++) {
        dp[i][0] = ((dp[i - 1][1] + dp[i - 1][2]) % MOD + dp[i - 1][4]) % MOD;
        dp[i][1] = (dp[i - 1][0] + dp[i - 1][2]) % MOD;
        dp[i][2] = (dp[i - 1][1] + dp[i - 1][3]) % MOD;
        dp[i][3] = dp[i - 1][2];
        dp[i][4] = (dp[i - 1][2] + dp[i - 1][3]) % MOD;
    }
    int ans = 0;
    for (int i = 0; i < 5; i++) {
        ans = (ans + dp[n][i]) % MOD;
    }
    return ans;
}

int main() {
    int n;
    cin >> n;
    cout << countVowelPermutation(n) << endl;
    return 0;
}
