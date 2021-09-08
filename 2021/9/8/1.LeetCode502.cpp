/*************************************************************************
	> File Name: 1.LeetCode502.cpp
	> Author: 
	> Mail: 
	> Created Time: 2021年09月08日 星期三 14时26分04秒
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

// DP, but TLE and MLE
struct Node {
    int profit;
    int capital;

    Node() = default;
    Node(int profit, int capital) : profit(profit), capital(capital) {}

    bool operator<(const struct Node &that) const {
        return this->capital == that.capital ? this->profit < that.profit : this->capital < that.capital;
    }
};

int findMaximizedCapital(int k, int w, vector<int>& profits, vector<int>& capital) {
    int n = profits.size();
    vector<Node> nodes;
    for (int i = 0; i < n; i++) nodes.push_back(move(Node(profits[i], capital[i])));
    sort(nodes.begin(), nodes.end());
    vector<vector<int>> dp(n + 1, vector<int>(k + 1, w));
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= min(k, i); j++) {
            dp[i][j] = dp[i - 1][j - 1] < nodes[i - 1].capital ? dp[i - 1][j] : max(dp[i - 1][j], dp[i - 1][j - 1] + nodes[i - 1].profit);
        }
    }
    return dp[n][k];
}

int main() {
    return 0;
}
