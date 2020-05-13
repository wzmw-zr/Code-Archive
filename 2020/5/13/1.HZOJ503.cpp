/*************************************************************************
	> File Name: 1.HZOJ503.cpp
	> Author:赵睿 
	> Mail: 1767153298@qq.com
	> Created Time: 2020年05月13日 星期三 18时01分55秒
 ************************************************************************/

#include<iostream>
#include<algorithm>
using namespace std;
#define MAX_N 30000

int w, n, ans;
int a[MAX_N + 5];

int main() {
    cin >> w >> n;
    for (int i = 0; i < n; i++) cin >> a[i];
    sort(a, a + n);
    int l = 0, r = n - 1;
    while (l < r) {
        ans++;
        if (a[l] + a[r] <= w) {
            l++, r--;
        } else {
            r--;
        }
    }
    if (l == r) ans++;
    cout << ans << endl;
    return 0;
}
