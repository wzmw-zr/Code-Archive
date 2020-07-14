/*************************************************************************
	> File Name: 1.LeetCode650.cpp
	> Author:赵睿 
	> Mail: 1767153298@qq.com
	> Created Time: 2020年07月15日 星期三 00时49分36秒
 ************************************************************************/

#include<iostream>
#include<cstdlib>
#include<cstring>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;

int minSteps(int n) {
    vector<int> dp(n + 5, 0x3f3f3f3f);
    dp[1] = 1;
    for (int i = 1; i <= n / 2; i++) {
        for (int j = 2 * i; j <= n; j += i) {
            if (j == 2 * i) dp[i]++;
            dp[j] = min(dp[j - i] + 1, dp[j]);
        }
    }
    return dp[n];
}

int main() {
    int n;
    cin >> n;
    cout << minSteps(n) << endl;
    return 0;
}
