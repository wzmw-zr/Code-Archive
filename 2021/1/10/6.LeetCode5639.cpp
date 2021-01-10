/*************************************************************************
	> File Name: 6.LeetCode5639.cpp
	> Author: 
	> Mail: 
	> Created Time: 2021年01月10日 星期日 11时21分20秒
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

bool check(vector<int> &jobs, vector<int> &times, int ind, int &threshold, int &ans) {
    if (ind == jobs.size()) {
        int mmax = INT32_MIN;
        for (int &x : times) mmax = max(mmax, x);
        ans = min(ans, mmax);
        return true;
    }
    bool state = false;
    for (int i = 0; i < times.size(); i++) {
        times[i] += jobs[ind];
        if (times[i] > threshold) {
            times[i] -= jobs[ind];
            continue;
        }
        state |= check(jobs, times, ind + 1, threshold, ans);
        times[i] -= jobs[ind];
    }
    return ans;
}

int minimumTimeRequired(vector<int>& jobs, int k) {
    vector<int> times(k, 0);
    int left = 0, right = 0, ans = INT32_MAX;
    for (int x : jobs) right += x;
    while (left < right) {
        int mid = (left + right) / 2;
        if (!check(jobs, times, 0, mid, ans)) {
            left = mid + 1;
            continue;
        }
        return ans;
    }
    return left;
}

#if 0
bool check(vector<int> &jobs, vector<int> &times, int ind, int &threshold) {
    if (ind == jobs.size()) return true;
    bool ans = false;
    for (int i = 0; i < times.size() && !ans; i++) {
        times[i] += jobs[ind];
        if (times[i] > threshold) {
            times[i] -= jobs[ind];
            continue;
        }
        ans |= check(jobs, times, ind + 1, threshold);
        times[i] -= jobs[ind];
    }
    return ans;
}

int minimumTimeRequired(vector<int>& jobs, int k) {
    vector<int> times(k, 0);
    int left = 0, right = 0;
    for (int x : jobs) right += x;
    while (left < right) {
        int mid = (left + right) / 2;
        if (check(jobs, times, 0, mid)) right = mid;
        else left = mid + 1;
    }
    return left;
}
#endif

int main() {
    int k, n;
    vector<int> jobs;
    cin >> k;
    while (cin >> n) jobs.push_back(n);
    cout << minimumTimeRequired(jobs, k) << endl;
    return 0;
}
