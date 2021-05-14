/*************************************************************************
	> File Name: 2.LeetCode1851.cpp
	> Author: 
	> Mail: 
	> Created Time: 2021年05月15日 星期六 00时30分40秒
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

// TLE

vector<int> minInterval(vector<vector<int>>& intervals, vector<int>& queries) {
    int q = queries.size();
    sort(intervals.begin(), intervals.end());
    vector<int> inds(q);
    for (int i = 0; i < q; i++) inds[i] = i;
    sort(inds.begin(), inds.end(), [&](int x, int y){
        return queries[x] < queries[y];
    });
    vector<int> res(q, -1);
    int l = 0, r = intervals.size();
    for (int i = 0; i < q; i++) {
        while ((l < r) && (intervals[l][1] < queries[inds[i]])) l++;
        if ((l == r) || (intervals[l][0] > queries[inds[i]])) continue;
        int ans = INT32_MAX;
        for (int j = l; j < r; j++) {
            if (intervals[j][0] > queries[inds[i]]) break;
            if (intervals[j][1] < queries[inds[i]]) continue;
            ans = min(ans, intervals[j][1] - intervals[j][0] + 1);
        }
        res[inds[i]] = (ans == INT32_MAX ? -1 : ans);
    }
    return res;
}

int main() {
    return 0;
}
