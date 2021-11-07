/*************************************************************************
	> File Name: 4.LeetCode5920.cpp
	> Author: 
	> Mail: 
	> Created Time: 2021年11月07日 星期日 10时58分02秒
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

int check(vector<int> &quantities, int mmax) {
    int cnt = 0;
    for (int x : quantities) cnt += x / mmax + ((x % mmax) ? 1 : 0);
    return cnt;
}

int minimizedMaximum(int n, vector<int>& quantities) {
    int wzmw_zr_q3 = 0;
    int mmax = INT32_MIN;
    for (int x : quantities) mmax = max(x, mmax);
    int l = 1, r = mmax;
    while (l < r) {
        int mid = (l + r) / 2;
        if (check(quantities, mid) <= n) r = mid;
        else l = mid + 1;
    }
    return l;
}

int main() {
    return 0;
}
