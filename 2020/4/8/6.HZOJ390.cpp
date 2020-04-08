/*************************************************************************
	> File Name: 6.HZOJ390.cpp
	> Author:赵睿 
	> Mail: 1767153298@qq.com
	> Created Time: 2020年04月08日 星期三 20时24分34秒
 ************************************************************************/

#include<iostream>
#include<algorithm>
using namespace std;

int n, m, mmax;
int x[100005];

int func(int len) {
    int cnt = 0;
    for (int i = 1; i <= n; i++) cnt += x[i] / len;
    return cnt;
}

int main() {
    cin >> n >> m;
    int max_len = 0;
    for (int i = 1; i <= n; i++) {
        cin >> x[i];
        mmax = max(mmax, x[i]);
    }
    int l = 1, r = mmax, mid;
    while (l <= r) {
        mid = (l + r + 1) >> 1;
        int s = func(mid);
        if (s >= m) l = mid;
        else r = mid - 1;
    }
    cout << l << endl;
    return 0;
}
