/*************************************************************************
	> File Name: 1.LeetCode1723.cpp
	> Author: 
	> Mail: 
	> Created Time: 2021年05月08日 星期六 00时30分37秒
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


bool dfs(vector<int> &jobs, vector<int> &work_times, int ind, int &n, int &k, int &mid) {
    if (ind == n) return true;
    bool ans = false;
    for (int i = 0; i < k && !ans; i++) {
        if ((work_times[i] + jobs[ind]) > mid) continue;
        work_times[i] += jobs[ind];
        ans |= dfs(jobs, work_times, ind + 1, n, k, mid);
        work_times[i] -= jobs[ind];
    }
    return ans;
}


int minimumTimeRequired(vector<int>& jobs, int k) {
    int mmax = 0;
    int n = jobs.size();
    for (int x : jobs)
        mmax += x;
    int l = 0, r = mmax;
    while (l < r) {
        vector<int> work_times(k, 0);
        int mid = (l + r) / 2;
        bool temp = dfs(jobs, work_times, 0, n, k, mid);
        if (temp) 
            r = mid;
        else 
            l = mid + 1;
    }
    return l;
}

int main() {
    return 0;
}
