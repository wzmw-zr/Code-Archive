/*************************************************************************
	> File Name: 2.LeetCode313.cpp
	> Author: 
	> Mail: 
	> Created Time: 2021年08月09日 星期一 10时28分49秒
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

int nthSuperUglyNumber(int n, vector<int>& primes) {
    int m = primes.size();
    vector<int> dp(n + 1, INT32_MAX);
    dp[1] = 1;
    vector<int> p(m, 1);
    for (int i = 2; i <= n; i++) {
        for (int j = 0; j < m; j++) dp[i] = min(dp[i], dp[p[j]] * primes[j]);
        for (int j = 0; j < m; j++) {
            if (dp[p[j]] * primes[j] == dp[i]) p[j]++;
        }
    }
    return dp[n];
}

int main() {
    return 0;
}
