/*************************************************************************
	> File Name: 2.LeetCode256.cpp
	> Author: 
	> Mail: 
	> Created Time: 2021年03月11日 星期四 20时03分00秒
 ************************************************************************/

#include<iostream>
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

int minCost(vector<vector<int>>& costs) {
    int n = costs.size();
    if (n == 0) return 0;
    for (int i = 1; i < n; i++) {
        costs[i][0] += min(costs[i - 1][1], costs[i - 1][2]);
        costs[i][1] += min(costs[i - 1][0], costs[i - 1][2]);
        costs[i][2] += min(costs[i - 1][0], costs[i - 1][1]);
    }
    return min(costs[n - 1][0], min(costs[n - 1][1], costs[n - 1][2]));
}

int main() {
    return 0;
}
