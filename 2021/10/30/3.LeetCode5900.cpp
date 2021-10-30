/*************************************************************************
	> File Name: 3.LeetCode5900.cpp
	> Author: 
	> Mail: 
	> Created Time: 2021年10月30日 星期六 22时58分57秒
 ************************************************************************/

#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <stack>
#include <map>
#include <set>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>
using namespace std;

int bs_last(vector<int> &nums, int l, int r, int t) {
    while (l < r) {
        int mid = (l + r + 1) / 2;
        if (nums[mid] <= t) l = mid;
        else r = mid - 1;
    }
    return l;
}

int bs_first(vector<int> &nums, int l, int r, int t) {
    while (l < r) {
        int mid = (l + r) / 2;
        if (nums[mid] >= t) r = mid;
        else l = mid + 1;
    }
    return l;
}

vector<int> platesBetweenCandles(string s, vector<vector<int>>& queries) {
    int wzmw_zr_q3 = 0;
    int n = s.size();
    vector<int> candle_cnts(n + 1, 0);
    for (int i = 0; i < n; i++) {
        candle_cnts[i + 1] = candle_cnts[i] + ((s[i] == '|') ? 1 : 0);
    }
    vector<int> ans;
    for (auto q : queries) {
        int l, r;
        if (s[q[0]] == '|') l = q[0] + 1;
        else {
            int cnt = candle_cnts[q[0] + 1];
            l = bs_last(candle_cnts, q[0] + 1, q[1] + 1, cnt) + 1;
        }
        if (s[q[1]] == '|') r = q[1] + 1;
        else {
            int cnt = candle_cnts[q[1] + 1];
            r = bs_first(candle_cnts, q[0] + 1, q[1] + 1, cnt) - 1;
        }
        ans.push_back(max(0, r - l + 1 - (candle_cnts[r] - candle_cnts[l - 1])));
    }
    return ans;
}

int main() {
    return 0;
}
