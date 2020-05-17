/*************************************************************************
	> File Name: 6.HZOJ250.cpp
	> Author:赵睿 
	> Mail: 1767153298@qq.com
	> Created Time: 2020年05月17日 星期日 20时12分09秒
 ************************************************************************/

#include<iostream>
#include<algorithm>
using namespace std;
#define MAX_N 1000000
long a[MAX_N + 5], s[MAX_N + 5], g[MAX_N + 5];
long n, sum, c, ans;

int main() {
    cin >> n;
    for (long i = 1; i <= n; i++) {
        cin >> a[i];
        s[i] = a[i] + s[i - 1];
        sum += a[i];
    }
    c = sum / n;
    for (long i = 1; i <= n; i++) {
        g[i] = s[i] - i * c;
    }
    sort(g + 1, g + 1 + n);
    c = g[n / 2];
    for (long i = 1; i <= n; i++) {
        ans += abs(g[i] - c);
    }
    cout << ans << endl;
    return 0;
}
