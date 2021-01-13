/*************************************************************************
	> File Name: 3.LeetCode1434.cpp
	> Author: 
	> Mail: 
	> Created Time: 2021年01月13日 星期三 01时28分30秒
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

void dfs(vector<long> &like, long &state, int ind, int &n, int &ans) {
    if (ind == n) {
        ans = (ans + 1) % 1000000007;
        return ;
    }
    long curState = state & like[ind];
    if (curState == 0) return ;
    while (curState) {
        int x = __builtin_ffs(curState);
        state &= ~(1 << (x - 1));
        dfs(like, state, ind + 1, n, ans);
        state |= (1 << (x - 1));
        curState &= ~(1 << (x - 1));
    }
}

int numberWays(vector<vector<int>>& hats) {
    int n = hats.size();
    long state = 0;
    int ans = 0;
    for (int i = 1; i <= 40; i++) state |= (1 << i);
    vector<long> like(n, 0);
    for (int i = 0; i < n; i++) {
        for (int &x : hats[i]) like[i] |= (1 << x);
    }
    dfs(like, state, 0, n, ans);
    return ans;
}

int main() {
    return 0;
}
