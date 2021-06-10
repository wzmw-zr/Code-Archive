/*************************************************************************
	> File Name: 1.LeetCode279.cpp
	> Author: 
	> Mail: 
	> Created Time: 2021年06月11日 星期五 00时02分59秒
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

int numSquares(int n) {
    vector<int> dp(n + 1, INT32_MAX);
    dp[0] = 0;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j * j <= i; j++) {
            dp[i] = min(dp[i], dp[i - j * j] + 1);
        }
    }
    return dp[n];
}

int main() {
    return 0;
}
