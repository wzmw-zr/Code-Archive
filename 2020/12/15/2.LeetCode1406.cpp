/*************************************************************************
	> File Name: 2.LeetCode1406.cpp
	> Author: 
	> Mail: 
	> Created Time: 2020年12月15日 星期二 08时41分14秒
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

string stoneGameIII(vector<int>& stoneValue) {
    int n = stoneValue.size();
    int dp[n];
    dp[n - 1] = stoneValue[n - 1];
    if (n >= 2) dp[n - 2] = max(stoneValue[n - 2] - dp[n - 1], stoneValue[n - 2] + stoneValue[n - 1]);
    if (n >= 3) dp[n - 3] = max(stoneValue[n - 3] - dp[n - 2], max(stoneValue[n - 3] + stoneValue[n - 2] - dp[n - 1], stoneValue[n - 3] + stoneValue[n - 2] + stoneValue[n - 1]));
    for (int i = n - 4; i >= 0; i--) {
        dp[i] = max(stoneValue[i] - dp[i + 1], stoneValue[i] + stoneValue[i + 1] - dp[i + 2]);
        dp[i] = max(dp[i], stoneValue[i] + stoneValue[i + 1] + stoneValue[i + 2] - dp[i + 3]);
    } 
    return dp[0] > 0 ? "Alice" : (dp[0] ? "Bob" : "Tie");
}

int main() {
    int n;
    vector<int> stoneValue;
    while (cin >> n) stoneValue.push_back(n);
    cout << stoneGameIII(stoneValue) << endl;
    return 0;
}
