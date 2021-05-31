/*************************************************************************
	> File Name: 1.LeetCode1744.cpp
	> Author: 
	> Mail: 
	> Created Time: 2021年06月01日 星期二 00时05分52秒
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

vector<bool> canEat(vector<int>& candiesCount, vector<vector<int>>& queries) {
    int n = candiesCount.size();
    int q = queries.size();
    vector<long> pre(n, 0);
    pre[0] = candiesCount[0];
    for (int i = 1; i < n; i++) 
        pre[i] = pre[i - 1] + (long) candiesCount[i];
    vector<bool> ans(q, false);
    for (int i = 0; i < q; i++) {
        int t = queries[i][0];
        long d = queries[i][1];
        long cap = queries[i][2];
        long cnt = pre[t];
        if (cnt <= d) continue; 
        long mmax = cap * (d + 1);
        long pre_cnt = pre[t] - (long) candiesCount[t];
        if (pre_cnt >= mmax) continue;
        ans[i] = true;
    }
    return ans;
}

int main() {
    return 0;
}
