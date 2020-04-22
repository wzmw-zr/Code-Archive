/*************************************************************************
	> File Name: 2.HZOJ391.cpp
	> Author:赵睿 
	> Mail: 1767153298@qq.com
	> Created Time: 2020年04月22日 星期三 18时04分02秒
 ************************************************************************/

#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<string>
using namespace std;
#define MAX_N 100000

long n, m, arr[MAX_N + 5], mmax, x;

long check(long mid) {
    int now = 0, cnt = 0;
    for (int i = 0; i < n; i++) {
        if (now + arr[i] == mid) {
            cnt++;
            now = 0;
        } else if (now + arr[i] > mid) {
            cnt++;
            now = arr[i];
        } else {
            now += arr[i];
        }
    }
    if (now) cnt++;
    return cnt;
}

long func() {
    long l = x, r = mmax;
    while (l != r) {
        long mid = (l + r) >> 1;
        long cnt = check(mid);
        if (cnt > m) l = mid + 1;
        else r = mid;
    }
    return l;
}

int main() {
    cin >> n >> m;
    for (long i = 0; i < n; i++) {
        cin >> arr[i];
        mmax += arr[i];
        x = max(x, arr[i]);
    }
    cout << func() << endl; 
    return 0;
}
