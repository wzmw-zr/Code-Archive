/*************************************************************************
	> File Name: 7.j.cpp
	> Author:赵睿 
	> Mail: 1767153298@qq.com
	> Created Time: 2020年05月30日 星期六 16时04分02秒
 ************************************************************************/

#include<iostream>
using namespace std;
#define MAX_N 200000
#define INF 0x3f3f3f3f

struct Data {
    long s, e, d, c;
} arr[MAX_N + 5];
long n;

long check(int pos) {
    long cnt = 0;
    for (long i = 0; i < n; i++) {
        if (arr[i].s > pos) continue;
        if (arr[i].e <= pos) {
            cnt += arr[i].c;
            continue;
        }
        cnt += (pos - arr[i].s) / arr[i].d + 1;
    }
    return cnt;
}

long bs(int l, int r) {
    if (l == r) return l;
    long mid = ((l ^ r) >> 1) + (l & r);
    if (check(mid) & 1) return bs(l, mid);
    return bs(mid + 1, r);
}

void solve() {
    long l = INF, r = -INF;
    cin >> n;
    for (long i = 0; i < n; i++) {
        cin >> arr[i].s >> arr[i].e >> arr[i].d;
        arr[i].c = (arr[i].e - arr[i].s) / arr[i].d + 1;
        if (i == 0) l = arr[i].s, r = arr[i].e;
        l = min(arr[i].s, l);
        r = max(arr[i].e, r);
    }
    long pos = bs(l, r);
    long cnt = check(pos) - check(pos - 1);
    if (cnt % 2) {
        cout << pos << " " <<  cnt << endl;
    } else {
        cout << "Poor QIN Teng:(" << endl;
    }
}

int main() {
    long tcase;
    cin >> tcase;
    while (tcase--) {
        solve();
    }
    return 0;
}
