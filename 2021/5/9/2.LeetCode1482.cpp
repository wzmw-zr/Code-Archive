/*************************************************************************
	> File Name: 2.LeetCode1482.cpp
	> Author: 
	> Mail: 
	> Created Time: 2021年05月09日 星期日 00时52分48秒
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

bool check(vector<int> &bloomDay, int &m, int &k, int day) {
    int cnt = 0;
    int exist = 0;
    for (int x : bloomDay) {
        if (x <= day) {
            exist++;
            if (exist < k) continue;
            cnt++;
            exist = 0;
            continue;
        } else {
            exist = 0;
        }
    }
    return cnt >= m;
}

int minDays(vector<int>& bloomDay, int m, int k) {
    int n = bloomDay.size();
    if (m * k > n) return -1;
    int mmax = 0;
    for (int x : bloomDay) mmax = max(mmax, x);
    int l = 1, r = mmax;
    while (l < r) {
        int mid = (l + r) / 2;
        if (check(bloomDay, m, k, mid)) r = mid;
        else l = mid + 1;
    }
    return l;
}

int main() {
    return 0;
}
