/*************************************************************************
	> File Name: 5.LeetCode5756.cpp
	> Author: 
	> Mail: 
	> Created Time: 2021年05月30日 星期日 20时53分02秒
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

int minimumXORSum(vector<int>& nums1, vector<int>& nums2) {
    int n = nums1.size();
    int dp[n + 1][(1 << n) + 1];
    memset(dp, 0x3f, sizeof(dp));
    dp[0][0] = 0;
    for (int i = 1; i <= n; i++) {
        for (int mask = 1; mask < (1 << n); mask++) {
            if (__builtin_popcount(mask) != i) continue;
            for (int j = 0; j < n; j++) {
                if (!(mask & (1 << j))) continue;
                dp[i][mask] = min(dp[i][mask], dp[i - 1][mask - (1 << j)] + (nums1[i - 1] ^ nums2[j]));
            }
        }
    }
    return dp[n][(1 << n) - 1];
}

int main() {
    return 0;
}
