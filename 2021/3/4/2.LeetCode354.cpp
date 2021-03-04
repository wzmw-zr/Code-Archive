/*************************************************************************
	> File Name: 2.LeetCode354.cpp
	> Author: 
	> Mail: 
	> Created Time: 2021年03月04日 星期四 09时26分53秒
 ************************************************************************/

#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;

int maxEnvelopes(vector<vector<int>>& envelopes) {
    if (envelopes.size() == 0) return 0;
    auto cmp = [](vector<int> &a, vector<int> &b) {
        return a[0] == b[0] ? a[1] > b[1] : a[0] < b[0];
    };
    sort(envelopes.begin(), envelopes.end(), cmp);
    int n = envelopes.size();
    vector<int> dp(n, 1);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < i; j++) {
            if (envelopes[i][1] > envelopes[j][1]) 
            dp[i] = max(dp[i], dp[j] + 1);
        }
    }
    return *max_element(dp.begin(), dp.end());
}

int main() {
    return 0;
}
