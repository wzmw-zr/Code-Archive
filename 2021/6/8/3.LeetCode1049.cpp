/*************************************************************************
	> File Name: 3.LeetCode1049.cpp
	> Author: 
	> Mail: 
	> Created Time: 2021年06月08日 星期二 00时33分17秒
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

void dfs(vector<int> &stones, int ind, int &n, int rest, int pre_sum, int &sum, int &ans) {
    if (rest == 0) {
        ans = min(ans, abs(sum - 2 * pre_sum));
        return ;
    }
    if (ind + rest > n) return ;
    dfs(stones, ind + 1, n, rest, pre_sum, sum, ans);
    dfs(stones, ind + 1, n, rest - 1, pre_sum + stones[ind], sum, ans);
}

int lastStoneWeightII(vector<int>& stones) {
    int n = stones.size();
    int sum = 0;
    int ans = INT32_MAX;
    for (int x : stones) sum += x;
    dfs(stones, 0, n, n / 2, 0, sum, ans);
    return ans;
}

int main() {
    return 0;
}
