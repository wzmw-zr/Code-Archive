/*************************************************************************
	> File Name: 1.LeetCode5786.cpp
	> Author: 
	> Mail: 
	> Created Time: 2021年06月13日 星期日 10时37分17秒
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

bool is_valid(string &s, string &p, vector<int> &removable, int cnt) {
    int len_1 = s.size(), len_2 = p.size();
    vector<int> check(len_1, 0);
    for (int i = 0; i < cnt; i++) check[removable[i]] = 1;
    int ind_1 = 0, ind_2 = 0;
    while ((ind_1 < len_1) && (ind_2 < len_2)) {
        if ((s[ind_1] != p[ind_2]) || check[ind_1]) {
            ind_1++;
            continue;
        }
        ind_1++, ind_2++;
    }
    return ind_2 == len_2;
}

int maximumRemovals(string s, string p, vector<int>& removable) {
    int n = removable.size();
    int l = 0, r = n;
    while (l < r) {
        int mid = (l + r + 1) / 2;
        if (is_valid(s, p, removable, mid)) l = mid;
        else r = mid - 1;
    }
    return l;
}

int main() {
    return 0;
}
