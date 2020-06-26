/*************************************************************************
	> File Name: 2.LeetCode343.cpp
	> Author:赵睿 
	> Mail: 1767153298@qq.com
	> Created Time: 2020年06月26日 星期五 08时56分13秒
 ************************************************************************/

#include<iostream>
#include<string>
#include<cstring>
#include<cstdlib>
#include<algorithm>
using namespace std;

int intergerBreak(int n) {
    int dp[n + 5];
    memset(dp, 0, sizeof(dp));
    dp[1] = 1;
    dp[2] = 1;
    for (int i = 3; i <= n; i++) {
        int mmax = 0;
        for (int j = 1; j < i; j++) {
            mmax = max(mmax, dp[j] * (i - j));
            mmax = max(mmax, j * (i - j));
        }
        dp[i] = mmax;
    }
    return dp[n];
}

int main() {
    int n;
    cin >> n;
    cout << intergerBreak(n) << endl;
    return 0;
}
