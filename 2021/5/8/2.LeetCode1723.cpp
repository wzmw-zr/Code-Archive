/*************************************************************************
	> File Name: 2.LeetCode1723.cpp
	> Author: 
	> Mail: 
	> Created Time: 2021年05月08日 星期六 01时06分14秒
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
    int work_time[1 << n];
    memset(work_time, 0, sizeof(work_time));
    for (int i = 1; i <= (1 << n); i++) {
        int x = __builtin_ctz(i);
        int y = i - (1 << x);
        work_time[i] = work_time[y] + jobs[x];
    }

    int dp[k][1 << n];
    memset(dp, 0, sizeof(dp));
    for (int i = 0; i < (1 << n); i++) 
        dp[0][i] = work_time[i];

    for (int i = 1; i < k; i++) {
        for (int j = 1; j < (1 << n); j++) {
            int mmin = INT32_MAX;
            for (int x = j; x; x = (x - 1) & j) {
                mmin = min(mmin, max(dp[i - 1][j - x], work_time[x]));
            }
            dp[i][j] = mmin;
        }
    }
    return dp[k - 1][(1 << n) - 1];
}


int main() {
    return 0;
}
