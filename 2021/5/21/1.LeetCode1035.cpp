/*************************************************************************
	> File Name: 1.LeetCode1035.cpp
	> Author: 
	> Mail: 
	> Created Time: 2021年05月21日 星期五 00时05分14秒
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

int maxUncrossedLines(vector<int>& nums1, vector<int>& nums2) {
    int n = nums1.size(), m = nums2.size();
    int dp[n + 1][m + 1];
    memset(dp, 0, sizeof(dp));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            dp[i + 1][j + 1] = max(dp[i + 1][j], dp[i][j + 1]);
            if (nums1[i] == nums2[j]) 
                dp[i + 1][j + 1] = max(dp[i + 1][j + 1], dp[i][j] + 1);
        }
    }
    return dp[n][m];
}

int main() {
    return 0;
}
