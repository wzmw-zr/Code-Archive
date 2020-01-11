/*************************************************************************
	> File Name: 8.HOJ82.cpp
	> Author:赵睿 
	> Mail: 1767153298@qq.com
	> Created Time: 2020年01月07日 星期二 20时34分42秒
 ************************************************************************/

#include<iostream>
#include<cstdio>
#include<string>
#include<cstring>
#include<cmath>
#include<cstdlib>
#include<inttypes.h>
#include<stdarg.h>
#include<algorithm>
#include<ctime>
#define max_n 1000000
using namespace std;

long tree[max_n + 5] = {0};
long best = 0, best_h = 0;

long get_sum(long mid) {
    long sum = 0;
    for (int i = 1; i <= tree[0]; i++) {
        if (tree[i] <= mid) continue;
        sum += (tree[i] - mid);
    }
    return sum;
}

long get_best(long left, long right, long m) {
    if (left > right) return best_h;
    long mid = (left + right) >> 1;
    long sum = get_sum(mid);
    if (sum == m) return mid;
    if (sum < m) {
        if (sum > best) best = sum, best_h = mid;
        right = mid - 1;
    } else {
        if (sum < best) best = sum, best_h = mid;
        left = mid + 1;
    }
    cout << "best = " << best << "best_h = " << best_h << endl;
    return get_best(left, right, m);
}

int main() {
    long n, m, highest = 2000000010;
    cin >> n >> m;
    tree[0] = n;
    for (long i = 1; i <= n; i++) cin >> tree[i];
    best_h = highest >> 1;
    best = get_sum(best_h);
    cout << get_best(0, highest, m) << endl;
    return 0;
}
