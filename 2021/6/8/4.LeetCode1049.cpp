/*************************************************************************
	> File Name: 4.LeetCode1049.cpp
	> Author: 
	> Mail: 
	> Created Time: 2021年06月08日 星期二 00时57分12秒
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

int lastStoneWeightII(vector<int>& stones) {
    int n = stones.size();
    int sum = 0;
    int ans = INT32_MAX;
    for (int x : stones) sum += x;
    vector<unordered_set<int>> pre_sum(n / 2 + 1, unordered_set<int>());
    pre_sum[0].insert(0);
    for (int i = 0; i < n; i++) {
        int last = min(i + 1, n / 2);
        for (int j = last - 1; j >= 0; j--) {
            for (int x : pre_sum[j]) 
                pre_sum[j + 1].insert(x + stones[i]);
        }
    }
    for (int i = 0; i <= n / 2; i++) {
        for (int x : pre_sum[i]) ans = min(ans, abs(sum - 2 * x));
    }
    return ans;
}

int main() {
    return 0;
}
