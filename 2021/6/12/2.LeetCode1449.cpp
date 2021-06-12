/*************************************************************************
	> File Name: 2.LeetCode1449.cpp
	> Author: 
	> Mail: 
	> Created Time: 2021年06月12日 星期六 21时39分25秒
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

bool isLarger(string &s1, string &s2) {
    int l1 = s1.size(), l2 = s2.size();
    return l1 == l2 ? s1 > s2 : l1 > l2;
}

string largestNumber(vector<int>& cost, int target) {
    vector<vector<string>> dp(10, vector<string>(target + 1, ""));
    for (int i = 1; i <= 9; i++) {
        if (cost[i - 1] <= target) dp[i][cost[i - 1]] = to_string(i);
    }
    for (int i = 1; i <= 9; i++) {
        for (int j = 1; j <= target; j++) {
            string temp = dp[i - 1][j];
            if ((j >= cost[i - 1]) && (dp[i][j - cost[i - 1]] != "")) {
                string t = to_string(i) + dp[i][j - cost[i - 1]];
                if (isLarger(t, temp)) temp = t;
            }
            if (isLarger(temp, dp[i][j])) dp[i][j] = temp;
        }
    }
    return dp[9][target] == "" ? "0" : dp[9][target];
}

int main() {
    return 0;
}
