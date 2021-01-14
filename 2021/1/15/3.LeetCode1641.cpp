/*************************************************************************
	> File Name: 3.LeetCode1641.cpp
	> Author: 
	> Mail: 
	> Created Time: 2021年01月15日 星期五 02时11分05秒
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

int countVowelStrings(int n) {
    int dp[5][n + 1];
    memset(dp, 0, sizeof(dp));
    for (int i = 0; i < 5; i++) dp[i][1] = 1;
    for (int i = 2; i <= n; i++) {
        for (int j = 0; j < 5; j++) {
            for (int k = j; k < 5; k++) dp[j][i] += dp[k][i - 1];
        }
    }
    return dp[0][n] + dp[1][n] + dp[2][n] + dp[3][n] + dp[4][n];
}

int main() {
    int n;
    cin >> n;
    cout << countVowelStrings(n) << endl;
    return 0;
}
