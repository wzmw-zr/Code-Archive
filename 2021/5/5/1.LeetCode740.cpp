/*************************************************************************
	> File Name: 1.LeetCode740.cpp
	> Author: 
	> Mail: 
	> Created Time: 2021年05月05日 星期三 00时02分16秒
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


const int MAX_N = 1e5;

int deleteAndEarn(vector<int>& nums) {
    vector<int> cnts(MAX_N + 5, 0);
    vector<int> dp(MAX_N + 5, 0);
    for (int x : nums) 
        cnts[x]++;
    int ans = cnts[1];
    dp[1] = cnts[1];
    for (int i = 2; i <= MAX_N; i++) {
        dp[i] = max(dp[i - 1], dp[i - 2] + i * cnts[i]);
        ans = max(ans, dp[i]);
    }
    return ans;
}

int main() {
    return 0;
}
