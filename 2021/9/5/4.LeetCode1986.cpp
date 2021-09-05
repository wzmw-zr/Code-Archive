/*************************************************************************
	> File Name: 4.LeetCode1986.cpp
	> Author: 
	> Mail: 
	> Created Time: 2021年09月05日 星期日 15时39分39秒
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

void build(vector<int> &tasks, int ind, int &n, vector<int> &sum, int state, int num) {
    if (ind == n) {
        sum[state] = num;
        return ;
    }
    build(tasks, ind + 1, n, sum, state, num);
    build(tasks, ind + 1, n, sum, state | (1 << ind), num + tasks[ind]);
}

int minSessions(vector<int>& tasks, int sessionTime) {
    int n = tasks.size();
    vector<int> sum(1 << n);
    vector<int> dp(1 << n, INT32_MAX);
    dp[0] = 0;
    build(tasks, 0, n, sum, 0, 0);
    for (int i = 1; i < (1 << n); i++) {
        for (int j = i; j; j = i & (j - 1)) {
            if (sum[j] <= sessionTime) dp[i] = min(dp[i], dp[i - j] + 1);
        }
    }
    return dp[(1 << n) - 1];
}

int main() {
    return 0;
}
