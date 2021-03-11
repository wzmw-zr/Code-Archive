/*************************************************************************
	> File Name: 3.LeetCode265.cpp
	> Author: 
	> Mail: 
	> Created Time: 2021年03月11日 星期四 20时08分55秒
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

int minCostII(vector<vector<int>>& costs) {
    int n = costs.size();
    if (n == 0) return 0;
    int k = costs[0].size();
    for (int i = 1; i < n; i++) {
        for (int j = 0; j < k; j++) {
            int mmin = INT32_MAX;
            for (int p = 0; p < k; p++) {
                if (j == p) continue;
                mmin = min(mmin, costs[i - 1][p]);
            }
            costs[i][j] += mmin;
        }
    }
    int ans = INT32_MAX;
    for (int i = 0; i < k; i++) ans = min(ans, costs[n - 1][i]);
    return ans;
}

int main() {
    return 0;
}
