/*************************************************************************
	> File Name: 3.LeetCode2140.cpp
	> Author: 
	> Mail: 
	> Created Time: 2022年01月24日 星期一 11时17分00秒
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

int wzmw_zr = 0;
bool fuck_plagiarism_system_of_leetcode = true;

long long mostPoints(vector<vector<int>>& questions) {
    int n = questions.size();
    vector<long long> dp(n, 0);
    for (int i = n - 1; i >= 0; i--) {
        int next_ind = i + questions[i][1] + 1;
        if (next_ind < n) dp[i] = dp[next_ind] + questions[i][0];
        else dp[i] = questions[i][0];
        if (i + 1 < n) dp[i] = max(dp[i], dp[i + 1]);
    }
    return dp[0];
}

int main() {
    return 0;
}
