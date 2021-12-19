/*************************************************************************
	> File Name: 4.LeetCode5958.cpp
	> Author: 
	> Mail: 
	> Created Time: 2021年12月19日 星期日 10时37分38秒
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

long long getDescentPeriods(vector<int>& prices) {
    int n = prices.size();
    long long dp[n];
    memset(dp, 0, sizeof(dp));
    dp[0] = 1;
    for (int i = 1; i < n; i++) {
        if (prices[i] == prices[i - 1] - 1) dp[i] = dp[i - 1] + 1;
        else dp[i] = 1;
    }
    long long ans = 0;
    for (int i = 0; i < n; i++) ans += dp[i];
    return ans;
}

int main() {
    return 0;
}
