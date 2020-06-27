/*************************************************************************
	> File Name: 3.LeetCode1406.cpp
	> Author:赵睿 
	> Mail: 1767153298@qq.com
	> Created Time: 2020年06月27日 星期六 14时19分17秒
 ************************************************************************/

#include<iostream>
#include<cstring>
#include<cstdlib>
#include<string>
#include<vector>
#include<queue>
#include<stack>
#include<algorithm>
#include<unordered_map>
#include<map>
using namespace std;

string stoneGameIII(vector<int>& stoneValue) {
    int len = stoneValue.size();
    int dp[len + 5], sum[len + 5];
    memset(dp, 0, sizeof(dp));
    memset(sum, 0, sizeof(sum));
    for (int i = 1; i <= len; i++) {
        sum[i] = sum[i - 1] + stoneValue[len - i];
        if (i == 1) 
            dp[i] = stoneValue[len - i];
        else if (i == 2) 
            dp[i] = max(
                sum[i - 1] - dp[i - 1] + stoneValue[len - i], 
                sum[i - 2] - dp[i - 2] + stoneValue[len - i] + stoneValue[len - i + 1]
                );
        else 
            dp[i] = max(
                sum[i - 1] - dp[i - 1] + stoneValue[len - i],
                max(sum[i - 2] - dp[i - 2] + stoneValue[len - i] + stoneValue[len - i + 1],
                sum[i - 3] - dp[i - 3] + stoneValue[len - i] + stoneValue[len - i + 1] + stoneValue[len - i + 2]
                ));
    }
    if (2 * dp[len] == sum[len]) return "Tie";
    if (2 * dp[len] < sum[len]) return "Bob";
    return "Alice";
}

int main() {
    int n;
    cin >> n;
    vector<int> stoneValue;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        stoneValue.push_back(x);
    }
    cout << stoneGameIII(stoneValue) << endl;
    return 0;
}
