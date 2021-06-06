/*************************************************************************
	> File Name: 4.LeetCode5779.cpp
	> Author: 
	> Mail: 
	> Created Time: 2021年06月06日 星期日 11时02分58秒
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

int find_right(vector<int> &packages, int num) {
    int l = 0, r = (int) packages.size() - 1;
    while (l < r) {
        int mid = (l + r + 1) / 2;
        if (packages[mid] <= num) l = mid;
        else r = mid - 1;
    }
    return l;
}

const long MOD = 1e9 + 7;

int minWastedSpace(vector<int>& packages, vector<vector<int>>& boxes) {
    int n = packages.size();
    sort(packages.begin(), packages.end());
    long sum = 0;
    for (int x : packages) sum += (long) x;
    long ans = INT64_MAX;
    for (auto &box : boxes) {
        sort(box.begin(), box.end());
        if (*packages.rbegin() > *box.rbegin()) continue;
        int l = -1;
        long t = 0;
        for (int x : box) {
            if (x < packages[0]) continue;
            int r = find_right(packages, x);
            if (l == r) continue;
            t += (long) x * (long) (r - l);
            l = r;
        }
        ans = min(ans, t - sum);
    }
    return ans == INT64_MAX ? -1 : ans % MOD;
}

int main() {
    return 0;
}
