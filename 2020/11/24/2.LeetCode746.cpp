/*************************************************************************
	> File Name: 2.LeetCode746.cpp
	> Author:赵睿 
	> Mail: 1767153298@qq.com
	> Created Time: 2020年11月24日 星期二 09时48分18秒
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

int minCostClimbingStairs(vector<int>& cost) {
    int n = cost.size();
    int dp[n];
    dp[0] = cost[0], dp[1] = cost[1];
    for (int i = 2; i < n; i++) dp[i] = min(dp[i - 1], dp[i - 2]) + cost[i];
    return min(dp[n - 1], dp[n - 2]);
}

int main() {
    int n;
    vector<int> cost;
    while (cin >> n) cost.push_back(n);
    cout << minCostClimbingStairs(cost) << endl;
    return 0;
}
