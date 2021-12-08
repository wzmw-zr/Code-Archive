/*************************************************************************
	> File Name: 1.LeetCode689.cpp
	> Author: 
	> Mail: 
	> Created Time: 2021年12月08日 星期三 09时31分32秒
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

vector<int> maxSumOfThreeSubarrays(vector<int>& nums, int k) {
    int n = nums.size();
    int dp[n + 1][3];
    int pre[n + 1][3];
    int pos[n + 1][3];
    memset(dp, 0, sizeof(dp));
    memset(pos, 0, sizeof(pos));
    int temp = 0;
    for (int i = 0; i < k; i++) temp += nums[i];
    for (int i = 0; i <= n - k; i++) {
        pre[i][0] = dp[i][0] = temp;
        pos[i][0] = i;
        if (i < n - k) temp += nums[i + k] - nums[i];
        if (i && pre[i][0] <= pre[i - 1][0]) pre[i][0] = pre[i - 1][0], pos[i][0] = pos[i - 1][0];
    }
    for (int i = k; i <= n - k; i++) {
        pre[i][1] = dp[i][1] = dp[i][0] + pre[i - k][0];
        pos[i][1] = i;
        if (i > k && pre[i][1] <= pre[i - 1][1]) pre[i][1] = pre[i - 1][1], pos[i][1] = pos[i - 1][1];
    }
    for (int i = 2 * k; i <= n - k; i++) {
        pre[i][2] = dp[i][2] = dp[i][0] + pre[i - k][1];
        pos[i][2] = i;
        if (i > 2 * k && pre[i][2] <= pre[i - 1][2]) pre[i][2] = pre[i - 1][2], pos[i][2] = pos[i - 1][2];
    }
    int mmax = INT32_MIN;
    for (int i = 2 * k; i <= n - k; i++) mmax = max(dp[i][2], mmax);
    vector<int> inds;
    for (int i = 2 * k; i <= n - k; i++) {
        if (dp[i][2] == mmax) inds.push_back(i);
    }
    vector<vector<int>> triples;
    for (int ind : inds) triples.push_back({pos[pos[ind - k][1] - k][0], pos[ind - k][1], ind});
    sort(triples.begin(), triples.end());
    return triples[0];
}

int main() {
    return 0;
}
