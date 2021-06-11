/*************************************************************************
	> File Name: 1.LeetCode1449.cpp
	> Author: 
	> Mail: 
	> Created Time: 2021年06月12日 星期六 00时09分28秒
 ************************************************************************/

#include <iostream>
#include <cstring>
#include <cstdlib>
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

// WA

bool isLarger(string &s1, string &s2) {
    return s1.size() == s2.size() ? s1 > s2 : s1.size() > s2.size();
}

string largestNumber(vector<int>& cost, int target) {
    vector<vector<string>> dp(10, vector<string>(target + 1, ""));
    for (int i = 0; i <= target; i++) {
        if (i >= cost[8]) dp[9][i] = dp[9][i - cost[8]] + '9';
    }
    for (int i = 8; i >= 1; i--) {
        for (int j = 0; j <= target; j++) {
            string t1 = dp[i + 1][j];
            if (j >= cost[i - 1]) {
                string t2 = dp[i][j - cost[i - 1]] + to_string(i);
                if (!isLarger(t1, t2))
                    t1 = t2;
            }
            dp[i][j] = t1;
        }
    }
    return dp[1][target];
}


int main() {
    return 0;
}
