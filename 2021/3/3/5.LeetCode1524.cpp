/*************************************************************************
	> File Name: 5.LeetCode1524.cpp
	> Author: 
	> Mail: 
	> Created Time: 2021年03月03日 星期三 23时40分16秒
 ************************************************************************/

#include<iostream>
#include<vector>
using namespace std;

const int MOD = 1e9 + 7;

int numOfSubarrays(vector<int>& arr) {
    int dp[2];
    dp[0] = dp[1] = 0;
    int cnt = 0, temp;
    for (int &x : arr) {
        if (x & 1) {
            temp = dp[0] + 1;
            dp[0] = dp[1];
            dp[1] = temp;
        } else dp[0]++;
        cnt += dp[1];
        if (cnt >= MOD) cnt -= MOD;
    }
    return cnt;
}


int main() {
    return 0;
}
