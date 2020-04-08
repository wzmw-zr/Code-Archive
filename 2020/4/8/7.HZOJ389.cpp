/*************************************************************************
	> File Name: 7.HZOJ389.cpp
	> Author:赵睿 
	> Mail: 1767153298@qq.com
	> Created Time: 2020年04月08日 星期三 20时48分26秒
 ************************************************************************/

#include<iostream>
#include<algorithm>
using namespace std;

int m, n, mmax;
int num[10005];

int func2(int len) {
    int cnt = 1, now = 1;
    for (int i = 2; i <= m; i++) {
        if (num[i] - num[now] >= len) cnt++, now = i;
    }
    return cnt;
}

int func() {
    int l = 0, r = mmax, mid;
    while (l < r) {
        int mid = (l + r + 1) >> 1;
        int cnt = func2(mid);
        if (cnt >= n) {
            l = mid;
        } else {
            r = mid - 1;
        }
    }
    return l;
}

int main() {
    cin >> m >> n;
    for (int i = 1; i <= m; i++) cin >> num[i];
    sort(num + 1, num + m + 1);
    mmax = num[m];
    cout << func() << endl;
    return 0;
}
