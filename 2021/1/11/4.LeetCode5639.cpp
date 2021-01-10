/*************************************************************************
	> File Name: 4.LeetCode5639.cpp
	> Author: 
	> Mail: 
	> Created Time: 2021年01月11日 星期一 02时48分59秒
 ************************************************************************/

#include<iostream>
#include<cstring>
#include<cstdlib>
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

int minimumTimeRequired(vector<int>& jobs, int k) {
    int n = jobs.size();
    vector<int> tot(1 << n, 0);
    for (int i = 0; i < (1 << n); i++) {
        for (int j = 0; j < n; j++) {
            if ((i & (1 << j)) == 0) continue;
            int left = i - (1 << j);
            tot[i] = tot[left] + jobs[j];
            break;
        }
    }

    vector<vector<int>> dp(k, vector<int>(1 << n, -1));
    for (int i = 0; i < (1 << n); i++) dp[0][i] = tot[i];
    for (int j = 1; j < k; j++) {
        for (int i = 0; i < (1 << n); i++) {
            int mmin = INT32_MAX;
            for (int s = i; s; s = (s - 1) & i) {
                int left = i - s;
                int val = max(dp[j - 1][left], tot[s]);
                mmin = min(mmin, val);
            }
            dp[j][i] = mmin;
        }
    }
    return dp[k - 1][(1 << n) - 1];
}

int main() {
    return 0;
}
