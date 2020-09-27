/*************************************************************************
	> File Name: 2.LeetCode616.cpp
	> Author:赵睿 
	> Mail: 1767153298@qq.com
	> Created Time: 2020年09月26日 星期六 07时51分46秒
 ************************************************************************/

#include<iostream>
#include<cstdlib>
#include<cstring>
#include<string>
#include<vector>
#include<queue>
#include<stack>
#include<map>
#include<set>
#include<algorithm>
using namespace std;

#define MAX_N 1010

struct Area {
    int x, y;

    Area(int x, int y) : x(x), y(y) {}
};

int sa[MAX_N << 1], rk[MAX_N << 1], old_rk[MAX_N << 1];
int n, w;

string addBoldTag(string s, vector<string>& dict) {
    vector<Area> area;
    n = s.size();
    s = " " + s;
    for (int i = 1; i <= n; i++) sa[i] = i, rk[i] = s[i];
    for (w = 1; w <= n; w <<= 1) {
        sort(sa + 1, sa + n, [](int a, int b){ return rk[a] == rk[b] ? rk[a + w] < rk[b + w] : rk[a] < rk[b]; });
        memcpy(old_rk, rk, sizeof(rk));
        for (int i = 1, p = 0; i <= n; i++) {
            if (old_rk[sa[i]] == old_rk[sa[i - 1]] && old_rk[sa[i] + w] == old_rk[sa[i - 1] + w]) rk[sa[i]] = p;
            else rk[sa[i]] = ++p;
        }
    }
    for (auto &x : dict) {
        int left = 1, right = n, mid = (left + right) / 2;
        while (left <= right) {
            mid = (left + right) / 2;
            int i;
            for (i = 0; x[i] && s[mid + i]; i++) {
                if (x[i] == s[mid + i]) continue;
                break;
            }
        }
    }
    return s;
}

int main() {
    return 0;
}
