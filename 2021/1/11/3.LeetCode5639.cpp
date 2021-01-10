/*************************************************************************
	> File Name: 3.LeetCode5639.cpp
	> Author: 
	> Mail: 
	> Created Time: 2021年01月11日 星期一 01时39分54秒
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

void dfs(int ind, vector<int> &jobs, vector<int> &times, int &k, int &ans) {
    if (ind == jobs.size()) {
        int mmax = times.back();
        for (int &x : times) mmax = max(mmax, x);
        ans = min(ans, mmax);
        return ;
    }
    for (int i = 0; i < k; i++) {
        times[i] += jobs[ind];
        dfs(ind + 1, jobs, times, k, ans);
        times[i] -= jobs[ind];
    }
}

int minimumTimeRequired(vector<int>& jobs, int k) {
    int ans = INT32_MAX;
    vector<int> times(k, 0);
    dfs(0, jobs, times, k, ans);
    return ans;
}

int main() {
    return 0;
}
