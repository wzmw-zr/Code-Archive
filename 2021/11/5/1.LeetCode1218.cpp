/*************************************************************************
	> File Name: 1.LeetCode1218.cpp
	> Author: 
	> Mail: 
	> Created Time: 2021年11月05日 星期五 12时53分43秒
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
using namespace std;

int longestSubsequence(vector<int>& arr, int difference) {
    unordered_map<int, int> dp;
    for (int x : arr) {
        if (!dp.count(x - difference)) {
            if (!dp.count(x)) dp[x] = 1;
            continue;
        }
        dp[x] = max(dp[x], dp[x - difference] + 1);
    }
    int ans = 1;
    for (auto &&[x, len] : dp) ans = max(ans, len);
    return ans;
}

int main() {
    return 0;
}
