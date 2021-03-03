/*************************************************************************
	> File Name: 4.LeetCode1524.cpp
	> Author: 
	> Mail: 
	> Created Time: 2021年03月03日 星期三 23时27分25秒
 ************************************************************************/

#include<iostream>
#include<cstring>
#include<cstdlib>
#include<vector>
using namespace std;

const int MOD = 1e9 + 7;

int numOfSubarrays(vector<int>& arr) {
    int n = arr.size(), cnt = 0;
    int dp[n + 1][2];
    memset(dp, 0, sizeof(dp));
    for (int i = 0; i < n; i++) {
        if (arr[i] & 1) {
            dp[i + 1][0] = dp[i][1];
            dp[i + 1][1] = dp[i][0] + 1;
        } else {
            dp[i + 1][0] = dp[i][0] + 1;
            dp[i + 1][1] = dp[i][1];
        }
        cnt = (cnt + dp[i + 1][1]) % MOD;
    }
    return cnt;
}

int main() {
    return 0;
}
