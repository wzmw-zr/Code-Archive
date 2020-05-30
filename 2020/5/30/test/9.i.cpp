/*************************************************************************
	> File Name: 9.i.cpp
	> Author:赵睿 
	> Mail: 1767153298@qq.com
	> Created Time: 2020年05月30日 星期六 16时20分28秒
 ************************************************************************/

#include<iostream>
#include<algorithm>
using namespace std;
#define MAX_N 10000

long n, ans;
long x[MAX_N + 5], y[MAX_N + 5];

int main() {
    cin >> n;
    for (long i = 0; i < n; i++) cin >> x[i] >> y[i];
    sort(x, x + n);
    sort(y, y + n);
    long y_m = y[n / 2];
    for (long i = 0; i < n; i++) ans += abs(y[i] - y_m);
    for (long i = 0; i < n; i++) x[i] -= i;
    sort(x, x + n);
    long x_m = x[n / 2];
    for (long i = 0; i < n; i++) ans += abs(x[i] - x_m);
    cout << ans << endl;
    return 0;
}
