/*************************************************************************
	> File Name: 2.HZOJ82.cpp
	> Author:赵睿 
	> Mail: 1767153298@qq.com
	> Created Time: 2020年04月25日 星期六 23时43分27秒
 ************************************************************************/

#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<string>
#include<vector>
#include<queue>
#include<stack>
#include<algorithm>
using namespace std;
#define MAX_N 1000000

long n, m, mmax;
long h[MAX_N + 5];

long Height(long l, long r) {
    long mid = 0;
    while (l < r) {
        mid = (l + r + 1) / 2;
        int res = 0;
        for (int i = 0; i < n; i++) if (h[i] > mid) res += h[i] - mid;
        if (res >= m) l = mid;
        else r = mid - 1;
    }
    return l;
}

int main() {
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        cin >> h[i];
        mmax = max(mmax, h[i]);
    }
    cout << Height(0, mmax) << endl;
    return 0;
}
